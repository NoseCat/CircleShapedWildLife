#pragma once
#include "PhysicsObject.h"
#include "GameObject.h"

enum class MsgType { Create, CreateGO, Kill, KillGO, PlayerMoved, PlayerCollide, KillPlayer, PlayerDamaged, PlayerAte };

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
		
		// Конструктор по умолчанию
	};
	
	MSG() : type(MsgType::Create), sender(nullptr) {};
};

