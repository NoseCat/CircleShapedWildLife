#pragma once
#include "MSG.h"
#include <list>

class Manager
{
private:
	static Manager* instance;

	std::list<GameObject*> Gobjs;
	std::list<PhysicsObject*> objs;
	std::list<MSG*> msgs;

	Manager();
	Manager(const Manager&);
	~Manager();

public:
	static Manager* GetInstance();
	static void Destroy();

	void Update(float dt);
	void SendMsg(MSG* m);
	void DrawObjects(sf::RenderWindow& win, Camera& cam);
};

