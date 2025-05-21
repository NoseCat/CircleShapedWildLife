#pragma once
#include "Item.h"
#include "Manager.h"

const sf::Color POISON_COLOR_MIN = sf::Color(55, 0, 70); // Dark purple
const sf::Color POISON_COLOR_MAX = sf::Color(180, 70, 255); // Bright purple
const float POISON_RADIUS_MIN = 25.0f;
const float POISON_RADIUS_MAX = 50.0f;

class Poison : public Item
{
private:
    ;
public:
    Poison(sf::Vector2f pos_) : Item(pos_, POISON_RADIUS_MIN, POISON_RADIUS_MAX, POISON_COLOR_MIN, POISON_COLOR_MAX)
    {
    }

    void Update(float dt)
    {
        Manager* MGR = Manager::GetInstance();
        MSG* msg = new MSG();
        msg->type = MsgType::FoodIsOn;
        msg->foodIsOn.food = this;
        msg->foodIsOn.pos = circle.getPosition();
        msg->foodIsOn.score = 0;
        msg->foodIsOn.size = circle.getRadius();
        msg->foodIsOn.poison = true;
        MGR->SendMsg(msg);
    }
    void SendMsg(MSG* m) { ; }
};