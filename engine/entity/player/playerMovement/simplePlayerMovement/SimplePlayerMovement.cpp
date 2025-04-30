#include "SimplePlayerMovement.hpp"
#include "../../Player.hpp"

void SimplePlayerMovement::move(Player* player, float deltaTime)
{
    if (Input::isKeyHeld(SDL_SCANCODE_LEFT))
    {
        player->setX(player->getX() - player->getSpeed() * deltaTime); // Move left
    }

    if (Input::isKeyHeld(SDL_SCANCODE_RIGHT))
    {
        player->setX(player->getX() + player->getSpeed() * deltaTime * 1.75f); // Move right
    }
    
    if (Input::isKeyHeld(SDL_SCANCODE_SPACE))
    {
        if (player->getIsOnGround()) // Check if the player is on the ground before jumping
        {
            player->jump(); 
        }
    } 

    player->applyGravity(deltaTime);
}
