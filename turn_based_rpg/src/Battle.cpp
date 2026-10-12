#include "Battle.h"

#include <iostream>
#include <random>

Battle::Battle(Player& player, Enemy& enemy)
    : player_(player),
      enemy_(enemy),
      generator_(std::random_device{}()),
      damage_distribution_(1, 100),
      item_distribution_(1, 6)
{
}

void Battle::run()
{
    applyStartingItem();

    while (player_.isAlive() && enemy_.isAlive())
    {
        const int player_attack_damage = rollDamage() + player_.damageBonus();
        enemy_.takeDamage(player_attack_damage);

        std::cout << "Player dealt " << player_attack_damage
                  << " damage to the monster.\n"
                  << "Monster health is: " << enemy_.health() << '\n';

        if (!enemy_.isAlive())
        {
            break;
        }

        const int enemy_attack_damage = rollDamage();
        player_.takeDamage(enemy_attack_damage);

        std::cout << "Monster dealt " << enemy_attack_damage
                  << " damage to player.\n"
                  << "Player health is: " << player_.health() << '\n';
    }

    if (!player_.isAlive())
    {
        std::cout << "The monster wins!\n";
    }
    else
    {
        std::cout << "The player wins!\n";
    }
}

void Battle::applyStartingItem()
{
    const int item = rollItem();
    std::cout << "Starting item roll: " << item << '\n';

    switch (item)
    {
    case 1:
        player_.setDamageBonus(10);
        break;
    case 2:
        player_.addHealth(100);
        break;
    case 3:
        player_.setDamageBonus(100);
        break;
    case 4:
        player_.setDamageBonus(50);
        break;
    case 5:
        enemy_.takeDamage(500);
        break;
    case 6:
        player_.setDamageBonus(500);
        break;
    default:
        break;
    }
}

int Battle::rollDamage()
{
    return damage_distribution_(generator_);
}

int Battle::rollItem()
{
    return item_distribution_(generator_);
}
