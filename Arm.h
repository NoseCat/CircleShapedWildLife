#pragma once
#include "Limb.h"
#include "VectorMath.h"
class Arm : public Limb
{
public:
	Arm(sf::Vector2f offset_) : Limb(offset_, 50, 5, 80, 10, { (float)(rand() % 800), (float)(rand() % 600) })
	{
		;
	}

	void Update(float dt)
	{
		step(curTarget);
	}

	void SendMsg(MSG* m)
	{
		;
	}
};



