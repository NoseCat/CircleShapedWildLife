#pragma once
#include "Enemy.h"
#include "Spider.h"
#include "Poison.h"
//#include "SpawnManager.h"

class Poisoner : public Enemy
{
private:
	float poisonTimer;
	float poisonTime;

public:
	Poisoner(sf::Vector2f pos) : Enemy(new Spider(), pos, 150, 2, 70)
	{
		poisonTimer = 0;
		poisonTime = 5;
	}

	virtual void Update(float dt)
	{
		poisonTimer += dt;
		if (poisonTimer > poisonTime)
		{
			poisonTimer = 0;
			new Poison(body->getPosition());
		}
		if (length(target - body->getPosition()) <= visibilityDistance)
		{
			target = sf::Vector2f({ (float)(rand() % MAP_WIDTH), (float)(rand() % MAP_HEIGTH) });
		}

		if (length(playerPos - body->getPosition()) <= touch)
		{
			Collide();
			Manager* MGR = Manager::GetInstance();
			MSG* msg = new MSG();
			msg->type = MsgType::PlayerCollide;
			msg->playerCollide.pos = body->getPosition();
			msg->playerCollide.Collider = (PhysicsObject*)this; //??
			MGR->SendMsg(msg);
		}

		sf::Vector2f dir = target - body->getPosition();
		Move(normalize(dir) * speed);
	}

	void Draw(sf::RenderWindow& window)
	{
	}

	virtual void SendMsg(MSG* m)
	{
		switch (m->type)
		{
		case MsgType::PlayerMoved:
			playerPos = m->playerMoved.newPos;
			break;
		case MsgType::PlayerCollide:
			break;
		default:
			break;
		}
	}

	virtual void Collide()
	{
		Manager* MGR = Manager::GetInstance();
		MSG* msg = new MSG();
		msg->type = MsgType::PlayerDamaged;
		msg->playerDamaged.damager = this;
		msg->playerDamaged.poison = true;

		MGR->SendMsg(msg);
	}
};

