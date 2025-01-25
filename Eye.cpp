#include "Eye.h"

void Eye::Draw(sf::RenderWindow& win)
{
	sf::CircleShape c(eyeSize);
	c.setOrigin(c.getRadius(), c.getRadius());
	c.setFillColor(sf::Color::White);
	//c.setPosition(circle.getPosition() + rotate(offset, rotation));
	c.setPosition(circle.getPosition() + transOffset);
	win.draw(c);

	c.setRadius(eyeSize / 2);
	c.setOrigin(c.getRadius(), c.getRadius());
	c.setFillColor(sf::Color::Black);
	sf::Vector2f target = (sf::Vector2f)sf::Mouse::getPosition(win) - (circle.getPosition() + transOffset);
	target = normalize(target);
	c.setPosition(circle.getPosition() + transOffset + target * pupilDistance);
	win.draw(c);
}