#pragma once
#include <SFML/Graphics.hpp>
#include "VectorMath.h"
#include "PhysicsObject.h"
#include "BodyPart.h"

class BodySegment : public PhysicsObject
{
private:
    std::vector<BodyPart*> bodyParts;

    //void virtual draw(sf::RenderWindow& window);
    //void drawPolyTo(sf::RenderWindow& window, const BodySegment& to);

public:
    BodySegment();
    BodySegment(float radius);

    void Update(float dt);
    void SendMsg(MSG* m);
    void Draw(sf::RenderWindow& win);

    sf::CircleShape getCircle();
    void setColor(sf::Color c);
    void move(sf::Vector2f vec);
    void virtual adjust(const BodySegment& to);
    void addPart(BodyPart* p);
    void fixPartOffset(const BodySegment& to);
};

