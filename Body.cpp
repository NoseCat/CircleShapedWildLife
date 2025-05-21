#include "Body.h"
#include <iostream>

Body::Body() : PhysicsObject({ 0,0 }, 0), segments()
{
}

void Body::add(int radius)
{
	segments.push_back(new BodySegment(radius));
}

void Body::adjust()
{
	for (int i = segments.size() - 1; i > 0; i--)
	{
		segments[i]->adjust(*(segments[i - 1]));
	}
}

void Body::move(sf::Vector2f dir)
{
	segments[0]->move(dir);
}

void Body::Update(float dt)
{
	for (int i = 0; i < segments.size() - 1; i++)
	{
		segments[i]->fixPartOffset(*(segments[i + 1]));
	}
	adjust();
	circle.setPosition(segments[0]->getCircle().getPosition());
}

sf::Vector2f Body::getPosition()
{
	return segments[0]->getCircle().getPosition();
}


void Body::setColor(int index, sf::Color c)
{
	segments[index]->setColor(c);
}

void Body::addBodyPart(int index, BodyPart* p)
{
	segments[index]->addPart(p);
}


void Body::SendMsg(MSG* m)
{
	;
}

void Body::Draw(sf::RenderWindow& window, Camera& cam)
{
	sf::ConvexShape poly;
	for (int i = segments.size() - 1; i > 0; i--)
	{
		poly = polyTwoCircles(segments[i]->getCircle(), segments[i - 1]->getCircle());
		poly.move(-cam.offset);
		window.draw(poly);
	}
}
