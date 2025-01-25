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

int main()
{
	//preprogramm
	sf::RenderWindow window(sf::VideoMode(800, 600), "Circles or smth");

	Manager* MGR = Manager::GetInstance();
	sf::Clock clock;
	clock.restart();

	//test
	//Body c = Body();
	//c.add(20);
	///*Eye* e = new Eye({10,-10});
	//c.segments[0]->addPart(e);
	//Eye* e2 = new Eye({-13,-5});
	//c.segments[0]->addPart(e2);
	//c.add(10);
	//c.add(10);
	//Leg* l = new Leg({ 10,0 }, {30, 100});
	//c.segments[2]->addPart(l);
	//Arm* l2 = new Arm({ -10,0 });
	//l2->invKnee();
	//c.segments[2]->addPart(l2);
	//c.add(10);
	//c.add(10);

	//std::vector<sf::CircleShape> circleShapes;
	//for (int i = 0; i < 3; i++)
	//{
	//	sf::CircleShape circle(10);
	//	circle.setOrigin(circle.getRadius(), circle.getRadius());
	//	circle.setFillColor(sf::Color::Magenta);
	//	circle.setPosition((float)(rand() % 100), (float)(rand() % 100));
	//	circleShapes.push_back(circle);
	//}
	//Blob* b = new Blob({1,0}, circleShapes);
	//c.segments[4]->addPart(b);
	//c.add(10);*/

	//Lizard* s = ;
	Creature* c = new Creature(new Lizard());


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
		MGR->Update(clock.restart().asSeconds());

		//test
		c->setTarget((sf::Vector2f)sf::Mouse::getPosition(window));

		//draw
		window.clear(sf::Color::Black);
		MGR->DrawObjects(window);
		window.display();
	}

	return 0;
}
