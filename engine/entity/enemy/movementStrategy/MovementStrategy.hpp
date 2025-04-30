#pragma once

class Enemy;
class Player;

class MovementStrategy
{
public:
    virtual ~MovementStrategy() = default;
    virtual void move(Enemy* enemy, Player* player, float deltaTime) = 0;
};
