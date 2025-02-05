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
		//body->move({1,1});
		speed = 2;
		target = { 0,0 };
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

