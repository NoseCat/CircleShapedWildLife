#pragma once
#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Camera
{
public:
	sf::Vector2f offset;

	static Camera* getInstance();
	static Camera* instance;
private:

	Camera() : offset({ 0,0 })
	{
		;
	}
};

