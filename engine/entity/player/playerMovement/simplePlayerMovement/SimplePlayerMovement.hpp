#pragma once

#include "../PlayerMovement.hpp"

class SimplePlayerMovement : public PlayerMovement 
{
public:
    void move(Player* player, float deltaTime) override;
};
