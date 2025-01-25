#pragma once
#include <SFML/Graphics.hpp>
#include "Limb.h"
#include "VectorMath.h"

class Leg : public Limb
{
public:

	Leg(sf::Vector2f offset_, sf::Vector2f target_) : Limb(offset_, 50, 5, 80, 10, target_)
	{
		;
	}

	//void Update(float dt)
	//{
	//	step();
	//}
	void SendMsg(MSG* m)
	{
		;
	}
	//void Draw(sf::RenderWindow& win);
};

