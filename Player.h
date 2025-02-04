#pragma once
#include "Creature.h"
#include "Manager.h"
#include "MSG.h"

class Player : public Creature
{
	virtual void Update(float dt)
	{
		sf::Vector2f input(0, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			input.y -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			input.y += 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			input.x -= 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			input.x += 1;
		}
		input = normalize(input);
		Move(input * speed);

		Manager* MGR = Manager::GetInstance();
		MSG* msg = new MSG();
		msg->type = MsgType::PlayerMoved;
		msg->playerMoved.newPos = body->getPosition();
		MGR->SendMsg(msg);
	}
	virtual void SendMsg(MSG* m)
	{

	}
};

