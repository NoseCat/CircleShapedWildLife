#pragma once
#include "Body.h"
#include "Blob.h"
#include "Leg.h"
#include "Eye.h"

class Spider : public Body
{
public:
	Spider() : Body()
	{
		sf::Color brown = { 135, 100, 10,255 };
		sf::Color darkerBrown = { 95, 64, 0, 255 };
		std::vector<sf::CircleShape> circleShapes1;
		std::vector<sf::CircleShape> circleShapes2;
		sf::CircleShape* c1 = new sf::CircleShape(5);
		c1->setOrigin(c1->getRadius(), c1->getRadius());
		c1->setPosition(0,0);
		c1->setFillColor(darkerBrown);
		sf::CircleShape* c2 = new sf::CircleShape(5);
		c2->setOrigin(c2->getRadius(), c2->getRadius());
		c2->setPosition(10, 10);
		c2->setFillColor(darkerBrown);
		sf::CircleShape* c3 = new sf::CircleShape(5);
		c3->setOrigin(c3->getRadius(), c3->getRadius());
		c3->setPosition(20, 0);
		c3->setFillColor(darkerBrown);
		circleShapes1.push_back(*c1);
		circleShapes1.push_back(*c2);
		circleShapes1.push_back(*c3);
		c2->setPosition(10, -10);
		circleShapes2.push_back(*c1);
		circleShapes2.push_back(*c2);
		circleShapes2.push_back(*c3);
		Blob* b1 = new Blob({-10, -25}, circleShapes1);
		Blob* b2 = new Blob({10, -25}, circleShapes2);
		add(30);
		setColor(0, brown);
		Eye* e1 = new Eye({ 15,0 });
		Eye* e2 = new Eye({ -15,0 });
		Eye* e3 = new Eye({ 12,15 });
		Eye* e4 = new Eye({ -12,15 });
		addBodyPart(0, e1);
		addBodyPart(0, e2);
		addBodyPart(0, e3);
		addBodyPart(0, e4);
		addBodyPart(0, b1);
		addBodyPart(0, b2);
		add(25);
		Leg* l1 = new Leg({ -10, 10 }, {-100, 10});
		l1->setColor(darkerBrown);
		addBodyPart(1, l1);
		Leg* l2 = new Leg({ -10, 5 }, {-100, 10});
		l2->setColor(darkerBrown);
		addBodyPart(1, l2);
		Leg* l3 = new Leg({ -5, 10 }, {-100, 10});
		l3->setColor(darkerBrown);
		addBodyPart(1, l3);
		Leg* l4 = new Leg({ -5, 15 }, {-100, 10});
		l4->setColor(darkerBrown);
		addBodyPart(1, l4);
		Leg* l5 = new Leg({ 10, 10 }, {-100, -10});
		l5->setColor(darkerBrown);
		l5->invKnee();
		addBodyPart(1, l5);
		Leg* l6 = new Leg({ 10, 5 }, {-100, -10});
		l6->setColor(darkerBrown);
		l6->invKnee();
		addBodyPart(1, l6);
		Leg* l7 = new Leg({ 5, 10 }, {-100, -10});
		l7->setColor(darkerBrown);
		l7->invKnee();
		addBodyPart(1, l7);
		Leg* l8 = new Leg({ 5, 15 }, {-100, -10});
		l8->setColor(darkerBrown);
		l8->invKnee();
		addBodyPart(1, l8);
		setColor(1, brown);
		add(50);
		setColor(2, darkerBrown);

	}

	//void Update(float dt) = 0;

	void SendMsg(MSG* m)
	{
		;
	}

	//void Draw(sf::RenderWindow& win);
};

