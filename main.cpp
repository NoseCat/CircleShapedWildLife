#include <SFML/Graphics.hpp>
#include "Manager.h"
#include "Camera.h"
#include "SpawnManager.h"

#include "Spider.h" //we need body for our player

int main()
{
	//preprogramm
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Circles or smth");

	Manager* MGR = Manager::GetInstance();
	sf::Clock clock;
	clock.restart();

	Camera* cam = Camera::getInstance();

	SpawnManager* spawnManager = new SpawnManager();
	Player* p = new Player(new Spider());
	spawnManager->assignPlayer(p);
	
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

		//draw
		window.clear(sf::Color::Black);
		MGR->DrawObjects(window, *cam);
		window.display();
	}

	return 0;
}
