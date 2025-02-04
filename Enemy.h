//#pragma once
//#include "Creature.h"
//#include "Manager.h"
//#include "MSG.h"
//#include "VectorMath.h"
//
//class Enemy : public Creature
//{
//	float visibilityDistance;
//	sf::Vector2f playerPos;
//
//	Enemy(Body* body) : Creature(body), visibilityDistance(10), playerPos({0,0})
//	{
//		;
//	}
//
//	virtual void Update(float dt)
//	{
//		//speed is aproximately low distance for this creature (one step away)
//		if (length(target - body->getPosition()) <= speed)
//		{
//			target = sf::Vector2f({ rand() % 2000, rand() % 2000 });
//		}
//
//		if (length(playerPos - body->getPosition()) <= visibilityDistance)
//		{
//			target = playerPos;
//		}
//
//		if (length(playerPos - body->getPosition()) <= speed )
//		{
//			Manager* MGR = Manager::GetInstance();
//			MSG* msg = new MSG();
//			msg->type = MsgType::Collide;
//			msg->collide.pos = body->getPosition();
//			msg->collide.Collider = this;
//			MGR->SendMsg(msg);
//		}
//
//		sf::Vector2f dir = target - body->getPosition();
//		Move(normalize(dir) * speed);
//	}
//	virtual void SendMsg(MSG* m)
//	{
//		switch (m->type)
//		{
//		case MsgType::PlayerMoved:
//			playerPos = m->playerMoved.newPos;
//			break;
//		case MsgType::Collide:
//			break;
//		default:
//			break;
//		}
//	}
//
//};
//
