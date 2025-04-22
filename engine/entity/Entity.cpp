#include "Entity.hpp"

Entity::Entity(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height), texture(nullptr)
{

}

void Entity::render(Renderer* renderer)
{
    if (texture != nullptr)
    {
        //renderer->renderTexture(texture, x, y, width, height);
    }
}

int Entity::getX() const { return x; }
int Entity::getY() const { return y; }
int Entity::getWidth() const { return width; }
int Entity::getHeight() const { return height; }

void Entity::setPosition(int newX, int newY) { x = newX; y = newY; }
