#pragma once
#include "Body.h"
#include "Blob.h"
#include "Leg.h"
#include "Eye.h"

class Snake : public Body
{
public:
	Snake() : Body()
	{
		sf::Color darkGreen = {0,100,0, 255};
		add(20);
		Eye* e1 = new Eye({ 15,0 });
		Eye* e2 = new Eye({ -15,0 });
		addBodyPart(0, e1);
		addBodyPart(0, e2);
		add(10);
		add(10);
		add(10);
		add(10);
		add(10);
		add(10);
		add(10);
		setColor(2, darkGreen);
		setColor(4, darkGreen);
		setColor(6, darkGreen);
	}

	//void Update(float dt) = 0;

	void SendMsg(MSG* m)
	{
		;
	}

	//void Draw(sf::RenderWindow& win);
};


