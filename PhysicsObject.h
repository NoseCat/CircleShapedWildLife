#pragma once
#include <SFML/Graphics.hpp>

struct MSG;

class PhysicsObject
{
private:
	static int lastID;

protected:
	int id;
	
	sf::CircleShape circle;
	//sf::Sprite sprite;

public:
	static int GetNewID();
	static int GetLastID();

	PhysicsObject();
	PhysicsObject(sf::Vector2f pos_, float radius_);
	PhysicsObject(sf::Vector2f pos_, float radius_, sf::Color color_);
	PhysicsObject(const PhysicsObject&);
	//virtual ~PhysicsObject();

	//int ID();

	virtual void Update(float dt) = 0;
	virtual void SendMsg(MSG* m) = 0;
	virtual void Draw(sf::RenderWindow& win);
};

