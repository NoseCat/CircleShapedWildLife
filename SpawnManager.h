#pragma once
#include "GameObject.h"
#include "MSG.h"
#include "Player.h"
#include "Predator.h"
#include "Poisoner.h"
#include "Prey.h"

class SpawnManager : public GameObject
{
	Player* p;

	int PredatorCounter = 0;
	int PredatorLimit = 5;
	bool SpawnPredators = false;
	int PreyCounter = 0;
	int PreyLimit = 5;
	bool SpawnPreys = true;
	int PoisonerCounter = 0;
	int PoisonerLimit = 5;
	bool SpawnPoisoners = false;

	int spawnTimer = 5;
	float spawnTimerAccumulator = 0;

public:

	SpawnManager() : GameObject()
	{
		p = nullptr;

		PredatorCounter = 0;
		PredatorLimit = 5;
		PreyCounter = 0;
		PreyLimit = 5;
		PoisonerCounter = 0;
		PoisonerLimit = 10;

		spawnTimer = 5;
		spawnTimerAccumulator = 0;
	}

	void Update(float dt)
	{
		bool spawn = false;
		spawnTimerAccumulator = spawnTimerAccumulator + dt;
		if (spawnTimerAccumulator > spawnTimer)
		{
			spawnTimerAccumulator = 0;
			spawn = true;
		}
	
		if (PredatorCounter < PredatorLimit && spawn && SpawnPredators)
		{
			PredatorCounter++;
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Predator spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Predator(randVec);
		}
		if (PoisonerCounter < PoisonerLimit && spawn && SpawnPoisoners)
		{
			PoisonerCounter++;
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Poisoner spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Poisoner(randVec);
		}
		if (PreyCounter < PreyLimit && spawn && SpawnPreys)
		{
			PreyCounter++;
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Poisoner spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Prey(randVec);
		}
	}

	void assignPlayer(Player* player)
	{
		p = player;
	}

	void Draw(sf::RenderWindow& window)
	{
	}

	void SendMsg(MSG* m)
	{
		switch (m->type)
		{
		case MsgType::PlayerMoved:
			break;
		case MsgType::PlayerCollide:
			break;
		case MsgType::PlayerAte:
			PreyCounter++;
			break;
		case MsgType::KillPlayer:

			MSG* msg = new MSG();
			msg->type = MsgType::Kill;
			//msg->kill.Dead = (PhysicsObject*)p; //??

			Manager* MGR = Manager::GetInstance();
			MGR->SendMsg(msg);

			break;
			//default:
				//break;
		}

	}
};

