#include "BodyPart.h"

sf::Vector2f BodyPart::getOffset()
{
	return trueOffset;
}
void BodyPart::setOffset(sf::Vector2f vec)
{
	transOffset = vec;
}

void BodyPart::setPosition(sf::Vector2f vec)
{
	circle.setPosition(vec);
}
