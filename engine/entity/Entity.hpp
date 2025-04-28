#pragma once

#include "../renderer/Renderer.hpp"

#include <SDL2/SDL.h>

class Entity
{
public:
    Entity(int x, int y, int width, int height);
    virtual ~Entity() = default;

    virtual void update() = 0; // Pure virtual function for updating the entity
    virtual void render(Renderer* renderer);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int setX(int newX);
    int setY(int newY);

    void setPosition(int newX, int newY);
    void checkCollisionWObj(const SDL_Rect& object);

protected:
    int x, y;
    int width, height;
    SDL_Texture* texture = nullptr;
};
