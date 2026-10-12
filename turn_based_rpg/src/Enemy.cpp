#include "Enemy.h"

Enemy::Enemy(int health)
    : health_(health)
{
}

int Enemy::health() const
{
    return health_;
}

void Enemy::takeDamage(int amount)
{
    health_ -= amount;
}

bool Enemy::isAlive() const
{
    return health_ > 0;
}
