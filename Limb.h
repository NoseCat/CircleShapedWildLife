#pragma once
#include "BodyPart.h"
#include "VectorMath.h"
#include <iostream>

class Limb : public BodyPart
{
private:
	sf::CircleShape feet;
	sf::CircleShape knee;
	float hipLength;
	float hipWidth = 10;
	float shinLength;
	bool invertKnee = false;

protected:
	sf::Vector2f offsetTarget;
	sf::Vector2f curTarget;

public:

	Limb(sf::Vector2f offset_, float hipLenght, float kneeSize, float shinLenght, float feetSize, sf::Vector2f target);

	void setHipWidth(float x)
	{
		hipWidth = x;
	}

	void step(sf::Vector2f target);

	void Draw(sf::RenderWindow& win);

	void Update(float dt);

	void invKnee()
	{
		invertKnee = !invertKnee;
	}

	bool getInvertKnee()
	{
		return invertKnee;
	}

	void setColor(sf::Color c)
	{
		knee.setFillColor(c);
		feet.setFillColor(c);
		circle.setFillColor(c);
	}

	void SendMsg(MSG* m)
	{
		;
	}
};

