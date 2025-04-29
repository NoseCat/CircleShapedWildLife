#pragma once
#include "iostream"
#include "Creature.h"
#include "Manager.h"
#include "MSG.h"
//#include "Camera.h"

class Player : public Creature
{
private:
	int health;
	int score;
	sf::Font font;
	sf::Text healthText;
	sf::Text scoreText;
public:

	sf::Vector2f getPosition()
	{
		return body->getPosition();
	}

	Player(Body* b) : Creature(b)
	{
		health = 100;
		score = 0;

		if (!font.loadFromFile("minecraft.ttf")) 
		{
			std::cout << "Font is not Loaded!!!!";
			return;
		}
		healthText.setFont(font);
		healthText.setString("Health: " + std::to_string(health));
		healthText.setCharacterSize(24);
		healthText.setFillColor(sf::Color::Red);
		healthText.setPosition(10, 10);

		scoreText.setFont(font);
		scoreText.setString("Score: " + std::to_string(score));
		scoreText.setCharacterSize(24);
		scoreText.setFillColor(sf::Color::Yellow);
		scoreText.setPosition(10, 40); 

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

	void Draw(sf::RenderWindow& window)
	{
		healthText.setString("Health: " + std::to_string(health));
		window.draw(healthText);
		scoreText.setString("Score: " + std::to_string(score));
		window.draw(scoreText);
	}

	virtual void SendMsg(MSG* m)
	{

	}
};

