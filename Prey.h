#pragma once
#include "Enemy.h"
#include "Snake.h"

class Prey : public Enemy
{
public:

	Prey(sf::Vector2f pos) : Enemy(new Snake(), pos, 250, 1.5, 40)
	{
	}

	virtual void Update(float dt)
	{
		if (length(target - body->getPosition()) <= touch)
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

		Manager* MGR = Manager::GetInstance();
		MSG* msg = new MSG();
		msg->type = MsgType::PreyMoved;
		msg->preyMoved.newPos = body->getPosition();
		msg->preyMoved.prey = (GameObject*)this; //??
		MGR->SendMsg(msg);
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
		case MsgType::PreyPredatorCollide:
			if(m->preyPredatorCollide.prey == (GameObject*)this)
			{
				Manager* MGR = Manager::GetInstance();
				MSG* msg = new MSG();
				msg->type = MsgType::KillGO;
				msg->killGO.Dead = (GameObject*)this;
				MGR->SendMsg(msg);
			}
			break;

		case MsgType::FoodIsOn:
			if (m->foodIsOn.poison)
			{
				return;
			}
			if (length(m->foodIsOn.pos - body->getPosition()) < m->foodIsOn.size + touch)
			{
				Manager* MGR = Manager::GetInstance();
				MSG* msg = new MSG();
				msg->type = MsgType::Kill;
				msg->kill.Dead = m->foodIsOn.food;
				MGR->SendMsg(msg);
			}
			if (length(m->foodIsOn.pos - body->getPosition()) < m->foodIsOn.size + visibilityDistance)
			{
				target = m->foodIsOn.pos;
			}
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

