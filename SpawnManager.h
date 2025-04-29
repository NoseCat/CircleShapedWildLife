#pragma once
#include "GameObject.h"
#include "MSG.h"
#include "Player.h"

const int MAP_WIDTH = 1000;
const int MAP_HEIGTH = 1000;

class SpawnManager : public GameObject
{
	Player* p;

	int PredatorCounter = 0;
	int PreyCounter = 0;
	int PoisonerCounter = 0;

public:

	//SpawnManager() : GameObject()
	//{

	//}

	void Update(float dt)
	{
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
			msg->kill.Dead = (PhysicsObject*)p; //??

			Manager* MGR = Manager::GetInstance();
			MGR->SendMsg(msg);
			
			break;
		//default:
			//break;
		}
	}
};

