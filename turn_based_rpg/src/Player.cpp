#include "Player.h"

Player::Player(int health)
    : health_(health), damage_bonus_(0)
{
}

int Player::health() const
{
    return health_;
}

int Player::damageBonus() const
{
    return damage_bonus_;
}

void Player::addHealth(int amount)
{
    health_ += amount;
}

void Player::setDamageBonus(int amount)
{
    damage_bonus_ = amount;
}

void Player::takeDamage(int amount)
{
    health_ -= amount;
}

bool Player::isAlive() const
{
    return health_ > 0;
}
