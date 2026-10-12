#pragma once

#include "Enemy.h"
#include "Player.h"

#include <random>

class Battle
{
public:
    Battle(Player& player, Enemy& enemy);
    void run();

private:
    void applyStartingItem();
    int rollDamage();
    int rollItem();

    Player& player_;
    Enemy& enemy_;
    std::mt19937 generator_;
    std::uniform_int_distribution<int> damage_distribution_;
    std::uniform_int_distribution<int> item_distribution_;
};
