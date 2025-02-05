#include "BodySegment.h"
#include <iostream>

BodySegment::BodySegment() : PhysicsObject({ 0,0 }, 0)
{
    circle.setFillColor(sf::Color::Green);
}

BodySegment::BodySegment(float radius) : PhysicsObject({ 0,0 }, radius)
{
    circle.setFillColor(sf::Color::Green);
}

void BodySegment::setPosition(sf::Vector2f pos)
{
    circle.setPosition(pos);
}

void BodySegment::adjust(const BodySegment& to)
{
    sf::Vector2f distance = to.circle.getPosition() - circle.getPosition();
    float disLen = length(distance);
    if (disLen < circle.getRadius() + to.circle.getRadius())
        return;

    disLen -= circle.getRadius() + to.circle.getRadius();
    distance = changeLength(distance, disLen);

    circle.move(distance);
}

void BodySegment::setColor(sf::Color c)
{
    circle.setFillColor(c);
}


void BodySegment::fixPartOffset(const BodySegment& to)
{
    sf::Vector2f distance = to.circle.getPosition() - circle.getPosition();
    float disLen = length(distance);
    if (disLen == 0)
        return;

    sf::Vector2f perp = { distance.y, -distance.x };
    perp = normalize(perp);
    distance = normalize(distance);
    for (auto bp : bodyParts)
    {
        bp->setOffset(perp * bp->getOffset().x + distance * bp->getOffset().y);
        //std::cout << bp->getOffset().x;
    }
}

void BodySegment::addPart(BodyPart *p)
{
    bodyParts.push_back(p);
}

void BodySegment::Draw(sf::RenderWindow& window, Camera& cam)
{
    sf::CircleShape c = circle;
    c.move(-cam.offset);
    window.draw(c);
}

void BodySegment::Update(float dt)
{
    for (auto bp : bodyParts)
    {
        bp->setPosition(circle.getPosition());
    }
}

void BodySegment::SendMsg(MSG* m)
{
}

sf::CircleShape BodySegment::getCircle()
{
    return circle;
}

void BodySegment::move(sf::Vector2f vec)
{
    circle.move(vec);
}


//void drawPolyTo(sf::RenderWindow& window, const BodySegment& to)
//{
//    sf::ConvexShape poly = polyTwoCircles(*this, to);
//    window.draw(poly);
//}