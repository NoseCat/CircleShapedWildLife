#pragma once
#include "Enemy.h"
#include "Snake.h"
//#include "SpawnManager.h"

class Prey : public Enemy
{
public:

	Prey(sf::Vector2f pos) : Enemy(new Snake(), pos, 250, 1.5, 40)
	{
	}

	virtual void Update(float dt)
	{
		if (length(target - body->getPosition()) <= visibilityDistance)
		{
			target = sf::Vector2f({ (float)(rand() % MAP_WIDTH), (float)(rand() % MAP_HEIGTH) });
		}

		if (length(playerPos - body->getPosition()) <= visibilityDistance)
		{
			target = this->body->getPosition() + (this->body->getPosition() - playerPos) * 2;
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
		msg->type = MsgType::PlayerAte;
		msg->playerAte.eaten = this;
		msg->playerAte.poison = false;
		MGR->SendMsg(msg);

		MSG* msg2 = new MSG();
		msg2->type = MsgType::KillGO;
		msg2->killGO.Dead = this;
		MGR->SendMsg(msg2);
	}
};

