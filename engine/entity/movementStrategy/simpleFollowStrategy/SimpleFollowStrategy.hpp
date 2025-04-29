#pragma once

#include "../MovementStrategy.hpp"

class SimpleFollowStrategy : public MovementStrategy
{
public:
    void move(Enemy* enemy, Player* player, float deltaTime) override;
};
