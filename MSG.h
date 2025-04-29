#pragma once
#include "PhysicsObject.h"
#include "GameObject.h"

enum class MsgType {Create, CreateGO, Kill, PlayerMoved, PlayerCollide, KillPlayer};

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
		
		// Конструктор по умолчанию
	};
	
	MSG() : type(MsgType::Create), sender(nullptr) {};
};

