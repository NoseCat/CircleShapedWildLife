#pragma once
#include <SFML/Graphics.hpp>

float length(sf::Vector2f vec);
sf::Vector2f normalize(sf::Vector2f vec);
sf::Vector2f operator+(sf::Vector2f a, sf::Vector2f b);
sf::Vector2f operator-(sf::Vector2f a, sf::Vector2f b);
sf::Vector2f operator*(sf::Vector2f vec, float val);
sf::Vector2f changeLength(sf::Vector2f vec, float len);
float angle(sf::Vector2f vec1, sf::Vector2f vec2);
sf::Vector2f rotate(sf::Vector2f vec, float degree);
float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2);

sf::ConvexShape polyTwoCircles(const sf::CircleShape& from, const sf::CircleShape& to);

