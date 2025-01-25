#include "GameObject.h"
#include "Manager.h"

int GameObject::lastID = 0;

int GameObject::GetNewID()
{
	return ++lastID;
}

int GameObject::GetLastID()
{
	return lastID;
}

GameObject::GameObject()
{
	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->createGO.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

GameObject::GameObject(sf::Vector2f pos_, float radius_)
{
	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->createGO.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

GameObject::GameObject(sf::Vector2f pos_, float radius_, sf::Color color_)
{
	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->createGO.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

GameObject::GameObject(const GameObject&)
{
	;
}

//void GameObject::Draw(sf::RenderWindow& win)
//{
//	;
//}