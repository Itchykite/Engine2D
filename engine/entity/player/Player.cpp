#include "Player.hpp"

Player::Player(int x, int y, int width, int height)
    : Entity(x, y, width, height)
{
   texture = nullptr; 
}

void Player::update()
{
    if(Input::isKeyPressed(SDLK_LEFT))
    {
        x -= 5;
    }
    if(Input::isKeyPressed(SDLK_RIGHT))
    {
        x += 5;
    }
    if(Input::isKeyPressed(SDLK_UP))
    {
        y -= 5;
    }
    if(Input::isKeyPressed(SDLK_DOWN))
    {
        y += 5;
    }
}

void Player::render(Renderer* renderer)
{
    Entity::render(renderer);
}
