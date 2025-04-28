#include "Player.hpp"
#include "../../input/InputManager.hpp"

Player::Player(int x, int y, int width, int height)
    : Entity(x, y, width, height)
{
    texture = nullptr; 
    speed = 5; // Set a default speed for the player
    jumpForce = -15; // Set a default jump force
}

void Player::applyGravity()
{
    if (!isOnGround)
    {
        velocityY += gravity;  // Apply gravity when not on the ground
    }
    else
    {
        velocityY = 0;  // Reset velocity when on the ground
    }

    y += velocityY;  // Update the player's position
}

void Player::jump()
{
    if (isOnGround)
    {
        velocityY = jumpForce; // Set the jump velocity
        isOnGround = false; // Player is now in the air
    }
}

void Player::update()
{
    if (Input::isKeyHeld(SDL_SCANCODE_LEFT))
    {
        x -= speed;
        SDL_Log("LEFT");
    }
    if (Input::isKeyHeld(SDL_SCANCODE_RIGHT))
    {
        x += speed;
        SDL_Log("RIGHT");
    }
    
    if (Input::isKeyHeld(SDL_SCANCODE_SPACE) && isOnGround)
    {
        jump();
        SDL_Log("JUMP");
    }
    
    applyGravity();
}

void Player::render(Renderer* renderer)
{
    renderer->drawRect(x, y, width, height); // Draw the player as a rectangle
}

