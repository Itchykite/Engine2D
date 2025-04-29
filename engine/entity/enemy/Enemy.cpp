#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int width, int heigth, MovementStrategy* strategy)
    :Entity(x, y, width, heigth), movementStrategy(strategy) 
{
    texture = nullptr;
    speed = 100; // Set a default speed for the enemy
}

void Enemy::update(float deltaTime)
{
}

void Enemy::applyGravity(float deltaTime)
{
    velocityY += 1000 * deltaTime; // grawitacja
    y += velocityY * deltaTime;
    isOnGround = false; // zakładamy, że spadamy, dopóki kolizja tego nie zmieni
}

void Enemy::update(Player* player, float deltaTime)
{
    if (movementStrategy) 
    {
        movementStrategy->move(this, player, deltaTime);
    }

    applyGravity(deltaTime);
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
