#pragma once
#include <SFML/Graphics.hpp>

struct MSG;

class GameObject
{
private:
	static int lastID;

protected:
	int id;

public:
	static int GetNewID();
	static int GetLastID();

	GameObject();
	GameObject(sf::Vector2f pos_, float radius_);
	GameObject(sf::Vector2f pos_, float radius_, sf::Color color_);
	GameObject(const GameObject&);
	//virtual ~PhysicsObject();

	//int ID();

	virtual void Update(float dt) = 0;
	virtual void SendMsg(MSG* m) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

