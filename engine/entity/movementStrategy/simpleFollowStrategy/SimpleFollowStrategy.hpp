#pragma once

#include "../MovementStrategy.hpp"

class SimpleFollowStrategy : public MovementStrategy
{
public:
    void move(Enemy* enemy, Player* player) override;
};
