#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int width, int heigth, MovementStrategy* strategy)
    :Entity(x, y, width, heigth), movementStrategy(strategy) 
{
    texture = nullptr;
    speed = 2; // Set a default speed for the enemy
}

void Enemy::update()
{

}

void Enemy::update(Player* player)
{
    if (movementStrategy) 
    {
        movementStrategy->move(this, player);
    }
}

void Enemy::render(Renderer* renderer)
{
    renderer->drawRect(x, y, width, height); // Draw the enemy as a rectangle
}

void Enemy::setMovementStrategy(MovementStrategy* strategy)
{
    movementStrategy = strategy;
}

int Enemy::getSpeed()
{
    return speed;
}
