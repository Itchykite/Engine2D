#include "Player.hpp"
#include "../../input/InputManager.hpp"

Player::Player(int x, int y, int width, int height)
    : Entity(x, y, width, height)
{
    texture = nullptr; 
    speed = 5; // Set a default speed for the player
}

void Player::update()
{
    if (Input::isKeyHeld(SDL_SCANCODE_LEFT))
    {
        x -= speed;
    }
    if (Input::isKeyHeld(SDL_SCANCODE_RIGHT))
    {
        x += speed;
    }
    if (Input::isKeyHeld(SDL_SCANCODE_UP))
    {
        y -= speed;
    }
    if (Input::isKeyHeld(SDL_SCANCODE_DOWN))
    {
        y += speed;
    }
}

void Player::render(Renderer* renderer)
{
    renderer->drawRect(x, y, width, height); // Draw the player as a rectangle
}

