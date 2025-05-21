#pragma once
#include "PhysicsObject.h"
#include "GameObject.h"

enum class MsgType { Create, CreateGO, Kill, KillGO, PlayerMoved, PlayerCollide, KillPlayer, PlayerDamaged, PlayerAte, PreyMoved, PreyPredatorCollide, FoodIsOn, GameEnd};

struct MSG
{
public: 

	MsgType type;
	PhysicsObject* sender;
	union 
	{
		struct
		{
			PhysicsObject* newObj;
		} create;

		struct
		{
			GameObject* newObj;
		} createGO;

		struct
		{
			PhysicsObject* Killer;
			PhysicsObject* Dead;
		} kill;

		struct
		{
			//PhysicsObject* Killer;
			GameObject* Dead;
		} killGO;

		struct 
		{
			sf::Vector2f oldPos;
			sf::Vector2f newPos;
		} playerMoved;

		struct
		{
			PhysicsObject* Collider;
			PhysicsObject* Collision;
			sf::Vector2f pos;
		} playerCollide;

		struct
		{
			PhysicsObject* Killer; 
			sf::Vector2f pos;
		} killPlayer;

		struct
		{
			GameObject* damager;
			bool poison;
		} playerDamaged;

		struct
		{
			GameObject* eaten;
			bool poison;
		} playerAte;

		struct
		{
			GameObject* prey;
			sf::Vector2f newPos;
		} preyMoved;

		struct
		{
			GameObject* prey;
			GameObject* Predator;
		} preyPredatorCollide;

		struct
		{
			PhysicsObject* food;
			sf::Vector2f pos;
			int score;
			bool poison;
			int size;
		} foodIsOn;
		
		struct
		{
			int score;
		} gameEnd;

		// Конструктор по умолчанию
	};

	MSG() : type(MsgType::Create), sender(nullptr) {};

	void print()
	{
		switch(this->type)
		{
		case MsgType::Create: printf("CREATE"); break;
		case MsgType::CreateGO: printf("CREATEGO"); break;
		case MsgType::FoodIsOn: printf("FOODISON"); break;
		case MsgType::GameEnd: printf("GAMEEND"); break;
		case MsgType::Kill: printf("KILL"); break;
		case MsgType::KillGO: printf("KILLGO"); break;
		case MsgType::KillPlayer: printf("KILLPLAYER"); break;
		case MsgType::PlayerAte: printf("PLAYERATE"); break;
		case MsgType::PlayerCollide: printf("PLAYERCOLLIDE"); break;
		case MsgType::PlayerDamaged: printf("PLAYERDAMAGED"); break;
		case MsgType::PlayerMoved: printf("PLAYERMOVED"); break;
		case MsgType::PreyMoved: printf("PREYMOVED"); break;
		case MsgType::PreyPredatorCollide: printf("PREYPREDATORCOLLIDE"); break;
		default: printf("msgdefault");
		}
		printf("\n");
	}
};

