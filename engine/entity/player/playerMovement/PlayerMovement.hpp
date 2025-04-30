#pragma once

class Player;

class PlayerMovement
{
public:
    virtual ~PlayerMovement() = default;
    virtual void move(Player* player, float deltaTime) = 0;
};
