#include "Manager.h"
#include <iostream>
#include <thread>

Manager* Manager::instance = nullptr;

Manager::Manager() : objs(), msgs() {}

Manager::Manager(const Manager&)
{
}

void Manager::ProcessKills()
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
}

Manager::~Manager()
{
	ProcessKills();
	for (auto x : Gobjs)
	{
		delete x;
		ProcessKills();
	}
	objs.clear();

	for (auto x : objs)
	{
		ProcessKills();
		delete x;
	}
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
	ProcessKills();

	//for (auto msg : msgs)
		//msg->print();

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

	for (auto Gobj : Gobjs)
		Gobj->Update(dt);

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

	for (auto msg : msgs)
	{
		if (msg->type == MsgType::GameEnd)
			End(win, msg->gameEnd.score);
	}
}

void End(sf::RenderWindow& window, int score)
{
	printf("\nEnd\n");
	//window.clear(sf::Color::Black);

	sf::Text YouDied;
	sf::Text YourScore;
	sf::Font font;
	font.loadFromFile("minecraft.ttf");
	YouDied.setFont(font);
	YouDied.setString("You Died");
	YouDied.setCharacterSize(32);
	YouDied.setFillColor(sf::Color::Red);

	YourScore.setFont(font);
	YourScore.setString("Your score: " + std::to_string(score));
	YourScore.setCharacterSize(32);
	YourScore.setFillColor(sf::Color::Yellow);

	sf::Vector2u windowSize = window.getSize();

	YouDied.setPosition((windowSize.x - YouDied.getLocalBounds().width) / 2.0f, windowSize.y * 0.4f);
	YourScore.setPosition((windowSize.x - YourScore.getLocalBounds().width) / 2.0f, YouDied.getPosition().y + YouDied.getLocalBounds().height + 20.0f);

	window.draw(YouDied);
	window.draw(YourScore);

	window.display();

	std::this_thread::sleep_for(std::chrono::seconds(4));
	exit(0);
}


