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
	auto killMessagge = msgs.begin();
	while (killMessagge != msgs.end())
	{
		MSG* m = *killMessagge;
		if (m->type == MsgType::Kill)
		{
			auto res = find(objs.begin(), objs.end(), m->kill.Dead);
			delete* res;
			objs.erase(res);
			
			delete m;
			killMessagge = msgs.erase(killMessagge);
		}
		else if (m->type == MsgType::KillGO)
		{
			auto res = find(Gobjs.begin(), Gobjs.end(), m->killGO.Dead);
			delete* res;
			Gobjs.erase(res);
			
			delete m;
			killMessagge = msgs.erase(killMessagge);
		}
		else
		{
			++killMessagge;
		}
	}

	MSG* m;
	while (!msgs.empty())
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
		case MsgType::KillGO:
		{
			auto res = find(Gobjs.begin(), Gobjs.end(), m->killGO.Dead);
			delete* res;
			Gobjs.erase(res);
		} break;

		case MsgType::KillPlayer:
		{

		}break;
		default:
			break;
		}

		for (auto obj : objs)
		{
			obj->SendMsg(m);
		}

		for (auto Gobj : Gobjs)
		{
			Gobj->SendMsg(m);
		}

		delete m;
	}

	for (auto obj : Gobjs)
		obj->Update(dt);

	for (auto obj : objs)
		obj->Update(dt);
}

void Manager::SendMsg(MSG* m)
{
	msgs.push_back(m);
}

void Manager::DrawObjects(sf::RenderWindow& win, Camera& cam)
{
	for (auto obj : objs)
	{
		obj->Draw(win, cam);
	}
	for (auto Gobj : Gobjs)
	{
		Gobj->Draw(win);
	}
}


