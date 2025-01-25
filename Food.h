#pragma once
#include "Item.h"

class Food : public Item
{
private:
	int saturation;
public:
	Food(sf::Vector2f pos_, float radius_, sf::Color color_, int saturation_);

	void Update(float dt) { ; };
	void SendMsg(MSG* m) { ; };

	//~Food() { ; };
};

