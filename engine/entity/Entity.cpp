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

void Entity::checkCollisionWObj(const SDL_Rect& object)
{
    SDL_Rect entityRect = { x, y, width, height };
    
    // Sprawdzamy, czy mamy kolizję
    if (SDL_HasIntersection(&entityRect, &object))
    {
        // Z której strony nastąpiła kolizja?
        int dx = 0, dy = 0;
        
        // Kolizja od góry
        if (y + height > object.y && y + height <= object.y + 5)
        {
            dy = object.y - height - y;  // Blokujemy na górze
        }
        // Kolizja od dołu
        else if (y < object.y + object.h && y >= object.y + object.h - 5)
        {
            dy = object.y + object.h - y;  // Blokujemy na dole
        }
        // Kolizja od lewej
        else if (x + width > object.x && x + width <= object.x + 5)
        {
            dx = object.x - width - x;  // Blokujemy z lewej
        }
        // Kolizja od prawej
        else if (x < object.x + object.w && x >= object.x + object.w - 5)
        {
            dx = object.x + object.w - x;  // Blokujemy z prawej
        }

        // Modyfikujemy pozycję, aby gracz nie przeszedł przez platformę
        x += dx;
        y += dy;
    }
}
