#pragma once
#include "BodyPart.h"
#include "VectorMath.h"
class Eye : public BodyPart
{
private:
	float eyeSize;
	float pupilDistance;

public:
	Eye(sf::Vector2f offset) : BodyPart(offset)
	{
		eyeSize = 10;
		pupilDistance = 4;
	}

	void setEyeSize(float radius)
	{
		eyeSize = radius;
	}

	void Draw(sf::RenderWindow& win);

	void Update(float dt)
	{
		;
	}

	void SendMsg(MSG* m)
	{
		;
	}
};

