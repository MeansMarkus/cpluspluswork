#include <iostream>
#include <random>

int main(){
    int player_health = 150;
    int monster_health = 1000;

    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> damage_distribution(1, 100);
    std::uniform_int_distribution<int> dice_distribution(1, 6);
    int sword_id = 1; //increase player dmg by 10
    int potion_id = 2;
    int rpg_id = 3; //increase player dmg by 100
    int spear_id = 4; //increase player damage by 50
    int shrink_potion_id = 5; //lowers monster
    int cat_id = 6; //increases dmg by 500;

    int result = 0;
    int player_damage_bonus = 0;

    result = dice_distribution(generator);
    std::cout << result << std::endl;

    if (result == sword_id)
    {
        player_damage_bonus = 10;
    }
    else if (result == potion_id)
    {
        player_health += 100;
    }
    else if (result == rpg_id)
    {
        player_damage_bonus = 100;
    }
    else if (result == spear_id)
    {
        player_damage_bonus = 50;
    }
    else if (result == shrink_potion_id)
    {
        monster_health -= 500;
    }
    else if (result == cat_id)
    {
        player_damage_bonus = 500;
    }

    while ( player_health > 0 && monster_health > 0)
    {
        int player_attack_damage = damage_distribution(generator) + player_damage_bonus;
        monster_health -= player_attack_damage;

        std::cout << "Player dealt " << player_attack_damage << " damage to the monster.\n"
                << "monster health is: " << monster_health << std::endl;

        if (monster_health <= 0)
        {
            break;
        }

        int monster_attack_damage = damage_distribution(generator);

        player_health -= monster_attack_damage;

        std::cout << "Monster dealt " << monster_attack_damage << " damage to player.\n"
              << "Player health is: " << player_health << std::endl;
        
        if (player_health <= 0)
        {
            break;
        }
    
        }

    if (player_health <= 0)
    {
        std::cout << "The monster wins!\n";
    }
    else
    {
        std::cout << "The player wins!\n";
    }

    return 0;
}