#pragma once
#include "GameObject.h"
#include "Body.h"
class Creature : public GameObject
{
protected:
	Body* body;

	sf::Vector2f target;
	float speed;
	//int health;
	//int attack;

public:
	Creature(Body* body) : GameObject(), body(body)
	{
		speed = 2;
		target = { 0,0 };
	}

	Creature(Body* body, float s) : GameObject(), body(body), speed(s)
	{
		target = { 0,0 };
	}

	virtual ~Creature()
	{
		Manager* MGR = Manager::GetInstance();
		MSG* msg = new MSG();
		msg->type = MsgType::Kill;
		msg->kill.Dead = (PhysicsObject*)body; //????
		MGR->SendMsg(msg);
	}

	virtual void Move(sf::Vector2f dir)
	{
		body->move(dir);
	}

	void setTarget(sf::Vector2f vec)
	{
		target = vec;
	}

	//virtual void Eat(Item* i)
	//{
	//	;
	//}

	virtual void Update(float dt)
	{
		sf::Vector2f dir = target - body->getPosition();
		Move(normalize(dir) * speed);
	}
	virtual void SendMsg(MSG* m)
	{

	}
};

