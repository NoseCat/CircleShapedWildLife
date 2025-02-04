#pragma once
#include "BodyPart.h"
#include "VectorMath.h"
class Blob : public BodyPart
{
private:
	std::vector<sf::CircleShape> circleShapes;
	std::vector<sf::Vector2f> circleShapesOffsets;
public:
    Blob(sf::Vector2f offset_, const std::vector<sf::CircleShape>& shapes) : BodyPart(offset_), circleShapes(shapes)
    {
        for (int i = 0; i < circleShapes.size(); i++)
        {
            sf::Vector2f vec = circleShapes[i].getPosition();
            circleShapesOffsets.push_back(vec);
        }
    }

    void Update(float dt)
    {
        for (int i = 0; i < circleShapes.size(); i++)
        {
            sf::Vector2f dist = normalize(transOffset);
            sf::Vector2f perp = { dist.y, -dist.x };
            circleShapes[i].setPosition(circle.getPosition() + transOffset + (dist * circleShapesOffsets[i].x + perp * circleShapesOffsets[i].y));
        }
    }
    void Draw(sf::RenderWindow& win, Camera& cam)
    {
        sf::ConvexShape poly;
        for (int i = 0; i < circleShapes.size(); i++)
        {
            sf::CircleShape c = circleShapes[i];
            c.move(-cam.offset);
            win.draw(c);
            //win.draw(circleShapes[i]);
            for (int j = i + 1; j < circleShapes.size(); j++)
            {
                poly = polyTwoCircles(circleShapes[i], circleShapes[j]);
                poly.move(-cam.offset);
                win.draw(poly);
            }
        }
    }
    void SendMsg(MSG* m)
    {
        ;
    }
};

