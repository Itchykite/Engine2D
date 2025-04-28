#pragma once

class Enemy;
class Player;

class MovementStrategy
{
public:
    virtual ~MovementStrategy() = default;
    virtual void move(Enemy* enemy, Player* player) = 0;
};
