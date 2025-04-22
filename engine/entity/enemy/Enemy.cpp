#include "Enemy.hpp"

Enemy::Enemy(int x, int y, int width, int heigth)
    :Entity(x, y, width, heigth)
{
    texture = nullptr;
}

void Enemy::update()
{
    x -= 2;

    if (x < 0)
    {
        x = 800;
    }
}

void Enemy::render(Renderer* renderer)
{
    Enemy::render(renderer);
}
