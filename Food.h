#pragma once
#include "Item.h"
#include "Manager.h"

const sf::Color FOOD_COLOR_MIN = sf::Color(25, 75, 25);    // Dark green
const sf::Color FOOD_COLOR_MAX = sf::Color(100, 255, 100);  // Bright green
const float FOOD_RADIUS_MIN = 5.0f;
const float FOOD_RADIUS_MAX = 25.0f;
const int SCORE_MIN = 1;
const int SCORE_MAX = 10;

class Food : public Item
{
private:
    int score;
public:
    Food(sf::Vector2f pos_) : Item(pos_, FOOD_RADIUS_MIN, FOOD_RADIUS_MAX, FOOD_COLOR_MIN, FOOD_COLOR_MAX),
        score(SCORE_MIN + rand() % (SCORE_MAX - SCORE_MIN + 1))
    {
    }

    void Update(float dt) 
    {
        Manager* MGR = Manager::GetInstance();
        MSG* msg = new MSG();
        msg->type = MsgType::FoodIsOn;
        msg->foodIsOn.food = this;
        msg->foodIsOn.pos = circle.getPosition();
        msg->foodIsOn.score = score;
        msg->foodIsOn.size = circle.getRadius();
        msg->foodIsOn.poison = false;
        MGR->SendMsg(msg);
    }
    void SendMsg(MSG* m) { ; }
};