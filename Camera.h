#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
	sf::Vector2f offset;

	Camera() : offset({ 0,0 })
	{
		;
	}
};

