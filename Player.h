#pragma once
#include "Creature.h"
#include "Manager.h"
#include "MSG.h"
//#include "Camera.h"

class Player : public Creature
{
public:

	sf::Vector2f getPosition()
	{
		return body->getPosition();
	}

	Player(Body* b) : Creature(b)
	{
		;
	}

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

		Camera* cam = Camera::getInstance();
		cam->offset = getPosition() - sf::Vector2f(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);

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

