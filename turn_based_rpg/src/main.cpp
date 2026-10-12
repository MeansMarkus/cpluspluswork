#include "Battle.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
    Player player;
    Enemy monster;
    Battle battle(player, monster);
    battle.run();

    return 0;
}
