#pragma once
#include "BodySegment.h"

class Body : PhysicsObject
{
private:
	std::vector<BodySegment*> segments;
public:
	Body();

	//~Body()
	//{
	//}

	//Body(const Body& c)
	//{
	//	;
	///*	size = c.size;
	//	for (int i = 0; i < c.size; i++)
	//		arr[i] = c.arr[i];*/
	//}

	void add(int radius);
	void addBodyPart(int index, BodyPart* p);
	void setColor(int index, sf::Color c);
	void adjust();
	void move(sf::Vector2f dir);
	sf::Vector2f getPosition();

	void Update(float dt);
	void SendMsg(MSG* m);
	void Draw(sf::RenderWindow& window, Camera& cam);
};

