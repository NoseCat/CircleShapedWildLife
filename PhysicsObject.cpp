#include "PhysicsObject.h"
#include "Manager.h"

int PhysicsObject::lastID = 0;

int PhysicsObject::GetNewID()
{
	return ++lastID;
}

int PhysicsObject::GetLastID()
{
	return lastID;
}

PhysicsObject::PhysicsObject()
{
	circle.setRadius(100);
	circle.setPosition({0,0});
	circle.setOrigin({circle.getRadius(), circle.getRadius() });
	circle.setFillColor(sf::Color::Red);

	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->create.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

PhysicsObject::PhysicsObject(sf::Vector2f pos_, float radius_)
{
	circle.setRadius(radius_);
	circle.setOrigin(radius_, radius_);
	circle.setPosition(pos_);
	circle.setFillColor(sf::Color::Red);

	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->create.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

PhysicsObject::PhysicsObject(sf::Vector2f pos_, float radius_, sf::Color color_) 
{
	circle.setRadius(radius_);
	circle.setOrigin(radius_, radius_);
	circle.setPosition(pos_);
	circle.setFillColor(color_);

	MSG* msg = new MSG;
	msg->type = MsgType::Create;
	msg->create.newObj = this;
	Manager* MGR = Manager::GetInstance();
	MGR->SendMsg(msg);
}

PhysicsObject::PhysicsObject(const PhysicsObject&)
{

}

void PhysicsObject::Draw(sf::RenderWindow& win, Camera& cam)
{
	sf::CircleShape c = circle;
	c.setPosition(c.getPosition() - cam.offset);
	win.draw(c);
}