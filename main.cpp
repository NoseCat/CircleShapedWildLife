#include <SFML/Graphics.hpp>
#include "Manager.h"

#include "BodySegment.h"
#include "Body.h"
#include "Eye.h"
#include "Leg.h"
#include "Arm.h"
#include "Blob.h"

#include "Spider.h"
#include "Snake.h"
#include "Lizard.h"
#include "Creature.h"

#include "Camera.h"

int main()
{
	//preprogramm
	sf::RenderWindow window(sf::VideoMode(800, 600), "Circles or smth");

	Manager* MGR = Manager::GetInstance();
	sf::Clock clock;
	clock.restart();

	Camera cam = Camera();
	cam.offset = { 10, 10};

	const int targetFPS = 60;
	const float frameTime = 1.0f / targetFPS;

	//test
	Creature* c = new Creature(new Snake());

	//Main loop
	while (window.isOpen())
	{
#pragma region EVENT
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
#pragma endregion //EVENT

		//update
		float deltaTime = clock.restart().asSeconds();
		MGR->Update(deltaTime);
		float waitTime = frameTime - deltaTime;
		if (waitTime > 0) 
			sf::sleep(sf::seconds(waitTime));

		//test
		c->setTarget((sf::Vector2f)sf::Mouse::getPosition(window));

		//draw
		window.clear(sf::Color::Black);
		MGR->DrawObjects(window, cam);
		window.display();
	}

	return 0;
}
