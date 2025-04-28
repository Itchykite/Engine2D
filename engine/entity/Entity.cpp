#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height), texture(nullptr)
{

}

void Entity::render(Renderer* renderer)
{
    
}

int Entity::getX() const { return x; }
int Entity::getY() const { return y; }
int Entity::getWidth() const { return width; }
int Entity::getHeight() const { return height; }
int Entity::setX(int newX) { x = newX; return x; }
int Entity::setY(int newY) { y = newY; return y; }

void Entity::setPosition(int newX, int newY) { x = newX; y = newY; }

void Entity::applyGravity()
{

}

void Entity::checkCollisionWObj(const SDL_Rect& object)
{
    SDL_Rect entityRect = { x, y, width, height };

    if (SDL_HasIntersection(&entityRect, &object))
    {
        if (velocityY >= 0 && (y + height - velocityY) <= object.y)
        {
            y = object.y - height;
            isOnGround = true;
            velocityY = 0; // Resetuj prędkość po lądowaniu
        }
        else
        {
            isOnGround = false;
        }
    }
    else
    {
        isOnGround = false;
    }
}
