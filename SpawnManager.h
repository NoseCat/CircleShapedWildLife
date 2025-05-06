#pragma once
#include "GameObject.h"
#include "MSG.h"
#include "Player.h"
#include "Predator.h"

class SpawnManager : public GameObject
{
	Player* p;

	int PredatorCounter = 0;
	int PredatorLimit = 5;
	int PreyCounter = 0;
	int PreyLimit = 5;
	int PoisonerCounter = 0;
	int PoisonerLimit = 5;

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
		PoisonerLimit = 5;

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
		if (PredatorCounter < PredatorLimit && spawn)
		{
			spawn = false;
			PredatorCounter++;
			sf::Vector2f randVec = sf::Vector2f((rand() % MAP_WIDTH), (rand() % MAP_HEIGTH));
			std::cout << "Predator spawned at x: " << randVec.x << "y: " << randVec.y << "\n";
			new Predator(randVec);
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

