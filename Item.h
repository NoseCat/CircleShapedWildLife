#pragma once
#include "PhysicsObject.h"
class Item : public PhysicsObject
{
private:
	//
public:
	Item(sf::Vector2f pos_, float radiusMin, float radiusMax, sf::Color colorMin, sf::Color colorMax) : PhysicsObject()
	{
		float randomRadius = radiusMin + (rand() / (RAND_MAX / (radiusMax - radiusMin)));
		circle.setRadius(randomRadius);
		circle.setOrigin(circle.getRadius(), circle.getRadius());

		//unsigned char
		sf::Uint8 r = colorMin.r + rand() % (colorMax.r - colorMin.r + 1);
		sf::Uint8 g = colorMin.g + rand() % (colorMax.g - colorMin.g + 1);
		sf::Uint8 b = colorMin.b + rand() % (colorMax.b - colorMin.b + 1);

		circle.setFillColor(sf::Color(r, g, b));
		circle.setPosition(pos_);
	}
};

