#include "Player.hpp"
#include "../../input/InputManager.hpp"

Player::Player(int x, int y, int width, int height, PlayerMovement* movement)
    : Entity(x, y, width, height), playerMovement(movement)
{
    texture = nullptr; 
    speed = 200; // Set a default speed for the player
    jumpForce = -500; // Set a default jump force
}

void Player::setPlayerMovement(PlayerMovement* movement)
{
    playerMovement = movement;
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
    if (playerMovement) 
    {
        playerMovement->move(this, deltaTime);
    }

    applyGravity(deltaTime);
}

void Player::render(Renderer* renderer)
{
    renderer->drawRect(x, y, width, height); // Draw the player as a rectangle
}

