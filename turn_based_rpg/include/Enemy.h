#pragma once

class Enemy
{
public:
    explicit Enemy(int health = 1000);

    int health() const;
    void takeDamage(int amount);
    bool isAlive() const;

private:
    int health_;
};
