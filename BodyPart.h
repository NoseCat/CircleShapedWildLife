#pragma once
#include "PhysicsObject.h"
class BodyPart : public PhysicsObject
{
protected:
	sf::Vector2f trueOffset;
	sf::Vector2f transOffset;
public:

	BodyPart() : PhysicsObject(), trueOffset({0,0})
	{
		transOffset = trueOffset;
	}

	BodyPart(sf::Vector2f offset_) : PhysicsObject(), trueOffset(offset_)
	{
		transOffset = trueOffset;
	}
	virtual ~BodyPart() = default;

	sf::Vector2f getOffset();
	void setOffset(sf::Vector2f vec);
	void setPosition(sf::Vector2f vec);
};

