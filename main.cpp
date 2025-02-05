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
#include "Player.h"
#include "Enemy.h"

#include "Camera.h"

int main()
{
	//preprogramm
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Circles or smth");

	Manager* MGR = Manager::GetInstance();
	sf::Clock clock;
	clock.restart();

	Camera* cam = Camera::getInstance();
	//cam->offset = { -100, -100};

	Player* p = new Player(new Spider());

	Enemy* e = new Enemy(new Snake());

	const int targetFPS = 60;
	const float frameTime = 1.0f / targetFPS;

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
		//c->setTarget((sf::Vector2f)sf::Mouse::getPosition(window));
		//std::cout << p->getPosition().x << " " << p->getPosition().y << std::endl;

		//draw
		window.clear(sf::Color::Black);
		MGR->DrawObjects(window, *cam);
		window.display();
	}

	return 0;
}
