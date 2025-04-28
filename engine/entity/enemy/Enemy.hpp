#pragma once

#include "../Entity.hpp"
#include "../movementStrategy/MovementStrategy.hpp"

class Enemy : public Entity 
{
public:
    Enemy(int x, int y, int width, int height, MovementStrategy* strategy);

    void update() override;
    void update(Player* player);
    void render(Renderer* renderer) override;

    void setMovementStrategy(MovementStrategy* strategy);

    int getSpeed();

private:
    MovementStrategy* movementStrategy;
    int speed;
};
