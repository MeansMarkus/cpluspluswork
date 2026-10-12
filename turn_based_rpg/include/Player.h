#pragma once

class Player
{
public:
    explicit Player(int health = 150);

    int health() const;
    int damageBonus() const;
    void addHealth(int amount);
    void setDamageBonus(int amount);
    void takeDamage(int amount);
    bool isAlive() const;

private:
    int health_;
    int damage_bonus_;
};
