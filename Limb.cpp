#include "Limb.h"

//Limb::
Limb::Limb(sf::Vector2f offset_, float hipLenght, float kneeSize, float shinLenght, float feetSize, sf::Vector2f target) :
	BodyPart(offset_), hipLength(hipLenght), knee(kneeSize), shinLength(shinLenght), feet(feetSize), offsetTarget(target)
{
	knee.setOrigin(knee.getRadius(), knee.getRadius());
	knee.setPosition({ 0,0 });
	knee.setFillColor(sf::Color::Blue);

	feet.setOrigin(feet.getRadius(), feet.getRadius());
	feet.setPosition({ 0,0 });
	feet.setFillColor(sf::Color::Blue);

	curTarget = offsetTarget;
}

void Limb::step(sf::Vector2f target)
{
	sf::Vector2f base = circle.getPosition() + transOffset;

	sf::Vector2f limbLength = feet.getPosition() - base;
	float basetofeetDistance = length(limbLength);

	float p = (hipLength + shinLength + basetofeetDistance) / 2.0f;
	float S = sqrt(p * (p - hipLength) * (p - shinLength) * (p - basetofeetDistance));
	float h = (2.0f * S) / basetofeetDistance;
	float angle = asin(h / hipLength);
	angle *= invertKnee ? -1 : 1;

	sf::Vector2f hipVec = normalize(limbLength) * hipLength;
	hipVec = rotate(hipVec, angle);

	sf::Vector2f newKneePos = base + hipVec;
	knee.setPosition(newKneePos);

	sf::Vector2f basetotarget = target - base;
	if (length(basetotarget) > hipLength + shinLength)
	{
		feet.setPosition(base + normalize(basetotarget) * (hipLength + shinLength));
	}
	else
	{
		feet.setPosition(target);
	}
}

void Limb::Draw(sf::RenderWindow& win)
{
	sf::ConvexShape poly = polyTwoCircles(knee, feet);
	win.draw(poly);

	sf::CircleShape base(hipWidth);
	base.setOrigin(base.getRadius(), base.getRadius());
	base.setPosition(circle.getPosition() + transOffset);
	poly = polyTwoCircles(knee, base);
	win.draw(poly);

	//feet.setFillColor(sf::Color::Red);
	//knee.setFillColor(sf::Color::Red);
	base.setFillColor(circle.getFillColor());
	win.draw(feet);
	win.draw(knee);
	win.draw(base);
}

void Limb::Update(float dt)
{
	float distance = length(curTarget - (circle.getPosition() + transOffset));
	if (distance > hipLength + shinLength)
	{
		sf::Vector2f dist = normalize(transOffset);
		sf::Vector2f perp = { dist.y, -dist.x };
		sf::Vector2f target = circle.getPosition() + transOffset + (dist * offsetTarget.x + perp * offsetTarget.y);
		curTarget = target;
	}
	step(curTarget);
}