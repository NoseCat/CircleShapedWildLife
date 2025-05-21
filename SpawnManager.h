#pragma once
#include "GameObject.h"
#include "MSG.h"
#include "Player.h"
#include "Predator.h"
#include "Poisoner.h"
#include "Prey.h"
#include "Food.h"
#include "Poison.h"

class SpawnManager : public GameObject
{
	Player* p;

	int PredatorCounter;
	int PredatorLimit;
	bool SpawnPredators = true;
	int PreyCounter;
	int PreyLimit;
	bool SpawnPreys = true;
	int PoisonerCounter;
	int PoisonerLimit;
	bool SpawnPoisoners = true;

	bool SpawnFood = true;
	bool SpawnPoison = true;

	int spawnTimer;
	float spawnTimerAccumulator;

public:

	SpawnManager() : GameObject()
	{
		p = nullptr;

		PredatorCounter = 0;
		PredatorLimit = 5;
		PreyCounter = 0;
		PreyLimit = 10;
		PoisonerCounter = 0;
		PoisonerLimit = 3;

		spawnTimer = 2.5;
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
			std::cout << "Prey spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Prey(randVec);
		}
		if (spawn && SpawnFood)
		{
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Food spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Food(randVec);
		}
		if (spawn && SpawnPoison)
		{
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Poison spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Poison(randVec);
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
		Manager* MGR = Manager::GetInstance();
		MSG* msg = new MSG();

		switch (m->type)
		{
		case MsgType::PlayerMoved:
			break;
		case MsgType::PlayerCollide:
			break;
		case MsgType::PreyPredatorCollide:
		case MsgType::PlayerAte:
			PreyCounter--;
			break;
		default:
			break;
		}
		delete msg;
	}
};

