#pragma once
#include "GameObject.h"
#include "Body.h"
class Creature : public GameObject
{
protected:
	Body* body;

	sf::Vector2f target;
	float speed;

public:
	Creature(Body* body) : GameObject(), body(body)
	{
		speed = 0.1;
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

	virtual void Update(float dt)
	{
		sf::Vector2f dir = target - body->getPosition();
		Move(normalize(dir) * speed);
	}
	virtual void SendMsg(MSG* m)
	{

	}
};

