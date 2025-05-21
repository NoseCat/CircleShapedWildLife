#pragma once
#include "Enemy.h"
#include "Lizard.h"
#include "VectorMath.h"
//#include "SpawnManager.h"

class Predator : public Enemy
{
public:

	Predator(sf::Vector2f pos) : Enemy(new Lizard(), pos, 250, 1, 50)
	{
		;
	}

	virtual void Update(float dt)
	{
		if (length(target - body->getPosition()) <= touch)
		{
			target = sf::Vector2f({ (float)(rand() % MAP_WIDTH), (float)(rand() % MAP_HEIGTH) });
		}

		if (length(playerPos - body->getPosition()) <= visibilityDistance)
		{
			target = playerPos;
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
		case MsgType::PreyMoved:
			if (length(m->preyMoved.newPos - body->getPosition()) < touch)
			{
				Manager* MGR = Manager::GetInstance();
				MSG* msg = new MSG();
				msg->type = MsgType::PreyPredatorCollide;
				msg->preyPredatorCollide.prey = m->preyMoved.prey;
				msg->preyPredatorCollide.Predator = this;

				MGR->SendMsg(msg);
			}
			if (length(m->preyMoved.newPos - body->getPosition()) < visibilityDistance)
				target = m->preyMoved.newPos;

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
		msg->playerDamaged.poison = false;
		
		MGR->SendMsg(msg);
	}
};

