#pragma once
#include "Body.h"
#include "Leg.h"
#include "Eye.h"
class Lizard : public Body
{
public:
	Lizard() : Body()
	{
		sf::Color darkGreen = { 0,100,0, 255 };
		add(30);
		Eye* e1 = new Eye({ 15,0 });
		Eye* e2 = new Eye({ -15,0 });
		addBodyPart(0, e1);
		addBodyPart(0, e2);
		add(20);
		add(20);
		add(20);
		add(20);
		add(10);
		add(10);
		add(10);
		add(10);
		add(10);

		Leg* l1 = new Leg({ -10, 10 }, { -100, 10 });
		l1->setColor(sf::Color::Green);
		addBodyPart(1, l1);
		Leg* l2 = new Leg({ 10, 5 }, { -100, -10 });
		l2->setColor(sf::Color::Green);
		l2->invKnee();
		addBodyPart(1, l2);

		Leg* l3 = new Leg({ -10, 10 }, { -100, 10 });
		l3->setColor(sf::Color::Green);
		addBodyPart(4, l3);
		Leg* l4 = new Leg({ 10, 5 }, { -100, -10 });
		l4->setColor(sf::Color::Green);
		l4->invKnee();
		addBodyPart(4, l4);
	}

	//void Update(float dt) = 0;

	void SendMsg(MSG* m)
	{
		;
	}

	//void Draw(sf::RenderWindow& win);
};
