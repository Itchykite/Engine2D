#include "Player.hpp"
#include "../../input/InputManager.hpp"

Player::Player(int x, int y, int width, int height)
    : Entity(x, y, width, height)
{
    texture = nullptr; 
    speed = 200; // Set a default speed for the player
    jumpForce = -500; // Set a default jump force
}

void Player::applyGravity(float deltaTime)
{
    velocityY += 1000 * deltaTime; // grawitacja
    y += velocityY * deltaTime;
    isOnGround = false; // zakładamy, że spadamy, dopóki kolizja tego nie zmieni
}

void Player::jump()
{
    velocityY = jumpForce; // Set the jump velocity
    isOnGround = false; // Player is now in the air
}

void Player::update(float deltaTime)
{
    if (Input::isKeyHeld(SDL_SCANCODE_LEFT))
    {
        x -= speed * deltaTime; // Move left    
        SDL_Log("LEFT dx: %f", speed * deltaTime);
    }

    if (Input::isKeyHeld(SDL_SCANCODE_RIGHT))
    {
        x += speed * deltaTime; // Move right
        SDL_Log("RIGHT dx: %f", speed * deltaTime);
    }
    
    if (Input::isKeyHeld(SDL_SCANCODE_SPACE))
    {
        if (isOnGround) // Check if the player is on the ground before jumping
        {
            jump(); 
        }
    } 

    applyGravity(deltaTime);

    SDL_Log("speed: %d, deltaTime: %f", speed, deltaTime);
}

void Player::render(Renderer* renderer)
{
    renderer->drawRect(x, y, width, height); // Draw the player as a rectangle
}

