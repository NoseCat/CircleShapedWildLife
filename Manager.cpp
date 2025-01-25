#include "Manager.h"

Manager* Manager::instance = nullptr;

Manager::Manager() : objs(), msgs() {}

Manager::Manager(const Manager&)
{
}

Manager::~Manager()
{
	for (auto x : Gobjs)
		delete x;
	objs.clear();

	for (auto x : objs)
		delete x;
	objs.clear();

	for (auto x : msgs)
		delete x;
	msgs.clear();
}

Manager* Manager::GetInstance()
{
	if (!instance) instance = new Manager();
	return instance;
}

void Manager::Destroy()
{
	if (instance) delete instance;
}

void Manager::Update(float dt)
{
	for (auto obj : Gobjs)
		obj->Update(dt);	
	
	for (auto obj : objs)
		obj->Update(dt);

	MSG* m;
	while(!msgs.empty())
	{
		m = msgs.front();
		msgs.pop_front();

		switch (m->type)
		{
		case MsgType::Create:
		{
			objs.push_back(m->create.newObj);
		} break;
		case MsgType::CreateGO:
		{
			Gobjs.push_back(m->createGO.newObj);
		} break;
		case MsgType::Kill:
		{
			auto res = find(objs.begin(), objs.end(), m->kill.Dead);
			delete* res;
			objs.erase(res);
		} break;
		case MsgType::Move:
		{
			//???
		} break;
		default:
			break;
		}

		for (auto obj : objs)
		{
			obj->SendMsg(m);
		}

		for (auto obj : Gobjs)
		{
			obj->SendMsg(m);
		}

		delete m;
	}

}

void Manager::SendMsg(MSG* m)
{
	msgs.push_back(m);
}

void Manager::DrawObjects(sf::RenderWindow& win)
{
	for (auto obj : objs)
	{
		obj->Draw(win);
	}
}


