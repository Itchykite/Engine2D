#pragma once

#include "../Entity.hpp"
#include "movementStrategy/MovementStrategy.hpp"

class Enemy : public Entity 
{
public:
    Enemy(int x, int y, int width, int height, MovementStrategy* strategy);

    void update(float deltaTime) override;
    void update(Player* player, float deltaTime);
    void render(Renderer* renderer) override;
    void applyGravity(float deltaTime) override;

    void setMovementStrategy(MovementStrategy* strategy);

    int getSpeed();

private:
    MovementStrategy* movementStrategy;
    int speed;
};
