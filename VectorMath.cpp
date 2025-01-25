#include "VectorMath.h"

float length(sf::Vector2f vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f normalize(sf::Vector2f vec)
{
	float len = length(vec);
	if (len == 0)
		return { 0.f, 0.f };
	else
	    return {vec.x / len, vec.y / len};
}

sf::Vector2f operator+(sf::Vector2f a, sf::Vector2f b)
{
	return { a.x + b.x, a.y + b.y };
}

sf::Vector2f operator-(sf::Vector2f a, sf::Vector2f b)
{
	return { a.x - b.x, a.y - b.y };
}

sf::Vector2f operator*(sf::Vector2f vec, float val)
{
	return { vec.x * val, vec.y * val};
}

sf::Vector2f changeLength(sf::Vector2f vec, float len)
{
	return normalize(vec) * len;
}

//this assumes the origin of a circle is in its center
sf::ConvexShape polyTwoCircles(const sf::CircleShape& from, const sf::CircleShape& to)
{
    //disect distance
    sf::Vector2f distance = to.getPosition() - from.getPosition();
    distance = normalize(distance);

    //find perpendicular
    sf::Vector2f perp = sf::Vector2f(-distance.y, distance.x);

    sf::Vector2f from1 = from.getPosition() + perp * from.getRadius();
    sf::Vector2f from2 = from.getPosition() + -perp * from.getRadius();
    sf::Vector2f to1 = to.getPosition() + perp * to.getRadius();
    sf::Vector2f to2 = to.getPosition() + -perp * to.getRadius();

    sf::ConvexShape polygon;
    polygon.setPointCount(4);
    polygon.setPoint(0, from1);
    polygon.setPoint(1, from2);
    //to1 and to2 swapped to antangle polygon 
    polygon.setPoint(2, to2);
    polygon.setPoint(3, to1);
    polygon.setFillColor(from.getFillColor());
    return polygon;
}

float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2)
{
    return  vec1.x * vec2.x + vec1.y * vec2.y;
}

//in radians
float angle(sf::Vector2f vec1, sf::Vector2f vec2)
{
    float dotProd = dotProduct(vec1, vec2);
    float len1 = length(vec1);
    float len2 = length(vec2);
    if (len1 == 0 || len2 == 0)
        return 0;

    float cosTheta = dotProd / (len1 * len2);
    return std::acos(cosTheta);
}

//degree in radians, rotates clockwise
sf::Vector2f rotate(sf::Vector2f vec, float degree)
{
    float cos = std::cos(degree);
    float sin = std::sin(degree);
    return { vec.x * cos - vec.y * sin, vec.x * sin + vec.y * cos };
}

