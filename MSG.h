#pragma once
#include "PhysicsObject.h"
#include "GameObject.h"

enum class MsgType {Create, CreateGO, Kill, Move, etc};

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
		} move;
		
		// Конструктор по умолчанию
	};
	
	MSG() : type(MsgType::Create), sender(nullptr) {};
};

