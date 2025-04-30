#pragma once

#include "../renderer/Renderer.hpp"

#include <SDL2/SDL.h>

class Entity
{
public:
    Entity(int x, int y, int width, int height);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0; // Pure virtual function for updating the entity
    virtual void render(Renderer* renderer);
    virtual void applyGravity(float deltaTime); // Gravity logic here

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    int setX(int newX);
    int setY(int newY);
    int getVelocityY() const { return velocityY; }
    int getIsOnGround() const { return isOnGround; }

    void setPosition(int newX, int newY);
    void checkCollisionWObj(const SDL_Rect& object);
    void intoAbyss() { y = 0;}

protected:
    int x, y;
    int width, height;
    SDL_Texture* texture = nullptr;

    int velocityY = 0;
    int gravity = 980;
    bool isOnGround = false;

};
