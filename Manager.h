#pragma once
#include "MSG.h"
#include <list>

const int MAP_WIDTH = 1000;
const int MAP_HEIGTH = 1000;

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

