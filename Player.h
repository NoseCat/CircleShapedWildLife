#pragma once
#include "iostream"
#include "Creature.h"
#include "Manager.h"
#include "MSG.h"

class Player : public Creature
{
private:
	int health;
	int score;
	sf::Font font;
	sf::Text healthText;
	sf::Text scoreText;

	bool invincible;
	float invincibilityTimer;
	float invincibilityTime;
	sf::CircleShape* invincibilityCircle;

	bool poisoned;
	float poisonTick;
	float poisonTickTimer;
	float poisonEffectDuration;
	float poisonTimer;
	sf::CircleShape* poisonCircle;

	int damage;
	int posionDamage;

public:

	sf::Vector2f getPosition()
	{
		return body->getPosition();
	}

	Player(Body* b) : Creature(b)
	{
		health = 100;
		score = 0;
		speed = 2;

		damage = 20;
		posionDamage = 1;

		invincible = false;
		invincibilityTimer = 0.0f;
		invincibilityTime = 2.0f;

		invincibilityCircle = new sf::CircleShape(150.0f);
		invincibilityCircle->setFillColor(sf::Color(0, 0, 255, 64));
		invincibilityCircle->setOrigin(invincibilityCircle->getRadius(), invincibilityCircle->getRadius());

		poisoned = false;
		poisonTick = 0.25f;
		poisonTickTimer = 0.0f;
		poisonEffectDuration = 5.0f;
		poisonTimer = poisonEffectDuration;

		poisonCircle = new sf::CircleShape(50.0f);
		poisonCircle->setFillColor(sf::Color(0, 255, 0, 32));
		poisonCircle->setOrigin(poisonCircle->getRadius(), poisonCircle->getRadius());

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
		invincibilityTimer += dt;
		invincible = !(invincibilityTimer > invincibilityTime);
		
		poisonTimer += dt;
		poisonTickTimer += dt;
		poisoned = (poisonTimer < poisonEffectDuration);
		if(poisoned)
			if (poisonTickTimer > poisonTick)
			{
				poisonTickTimer = 0;
				health -= posionDamage;
			}

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

		if (health <= 0)
		{
			MSG* msg = new MSG();
			msg->type = MsgType::GameEnd;
			msg->gameEnd.score = score;
			MGR->SendMsg(msg);
		}
	}

	void Draw(sf::RenderWindow& window)
	{
		invincibilityCircle->setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		if (invincible)
			window.draw(*(invincibilityCircle));
		poisonCircle->setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		if (poisoned)
			window.draw(*(poisonCircle));

		healthText.setString("Health: " + std::to_string(health));
		window.draw(healthText);
		scoreText.setString("Score: " + std::to_string(score));
		window.draw(scoreText);
	}

	void MakeTemporaryInvincible()
	{
		invincible = true;
		invincibilityTimer = 0;
	}

	void Poison()
	{
		poisoned = true;
		poisonTimer = 0;
		poisonTickTimer = 0;
	}

	virtual void SendMsg(MSG* m)
	{
		Manager* MGR = Manager::GetInstance();
		switch (m->type)
		{
		case MsgType::PlayerDamaged:
			if (!invincible)
			{
				if (m->playerDamaged.poison)
				{
					Poison();
				}
				else
					health -= damage;
				MakeTemporaryInvincible();
			}
			break;
		case MsgType::PlayerAte:
			score += 15;
			break;
		case MsgType::FoodIsOn:
			if (!(length(m->foodIsOn.pos - body->getPosition()) < m->foodIsOn.size))
			{
				return;
			}
			if (m->foodIsOn.poison)
			{
				Poison();
			}
			score += m->foodIsOn.score;
			MSG* msg = new MSG();
			msg->type = MsgType::Kill;
			msg->kill.Dead = m->foodIsOn.food;
			MGR->SendMsg(msg);
			break;
		}
	}
};

