#pragma once
#include "Creature.h"
#include "Manager.h"
#include "MSG.h"
#include "VectorMath.h"

class Enemy : public Creature
{
public:
	float visibilityDistance;
	sf::Vector2f playerPos;
	float touch;

	Enemy(Body* body, sf::Vector2f pos, float vd, float s, float touch) : Creature(body, s), 
		visibilityDistance(vd), playerPos(pos), touch(touch)
	{
		Move(pos);
	}

	virtual void Update(float dt)
	{
		;
	}

	virtual void SendMsg(MSG* m)
	{
		switch (m->type)
		{
		case MsgType::PlayerMoved:
			playerPos = m->playerMoved.newPos;
			break;
		case MsgType::PlayerCollide:
			Collide();
			break;
		default:
			break;
		}
	}

	virtual void Collide()
	{
		;
	}
};

