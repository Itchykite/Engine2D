#include "Game.hpp"
#include "../engine/input/InputManager.hpp"
#include "../engine/entity/player/Player.hpp"
#include "../engine/entity/player/playerMovement/simplePlayerMovement/SimplePlayerMovement.hpp"
#include "../engine/entity/enemy/Enemy.hpp"
#include "../engine/entity/enemy/movementStrategy/simpleFollowStrategy/SimpleFollowStrategy.hpp"
#include "../engine/renderer/platform/Platform.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <random>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int GROUND_LEVEL = 600;
const int WORLD_WIDTH = 5000;
const int WORLD_HEIGHT = 2000;

class MyGame : public Game
{
private:
    SimpleFollowStrategy* followStrategy = nullptr;
    SimplePlayerMovement* playerMovement = nullptr;
    Player* player = nullptr;
    Enemy* enemy = nullptr;
    Camera* camera = nullptr; // Camera instance

    std::vector<Platform> platforms; // Vector to hold platforms

public:
    MyGame()
    {
        followStrategy = new SimpleFollowStrategy();
        playerMovement = new SimplePlayerMovement();
        camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT); // Initialize camera with screen dimensions

        player = new Player(100, 100, 50, 50, playerMovement);
        enemy = new Enemy(200, 200, 50, 50, followStrategy);

        initPlatforms(); 
    }

    ~MyGame()
    {
        delete player;
        delete enemy;
        delete followStrategy;              
        delete camera;

        platforms.clear();
    } 

    void initPlatforms()
    {
        platforms.push_back(Platform(0, GROUND_LEVEL, WORLD_WIDTH, 20)); // Ground platform
        platforms.push_back(Platform(0, WORLD_HEIGHT, WORLD_WIDTH, 20)); // Top platform
        platforms.push_back(Platform(0, GROUND_LEVEL, 20, -(WORLD_HEIGHT))); // Left platform
        platforms.push_back(Platform(WORLD_WIDTH - 20, GROUND_LEVEL, 20, -(WORLD_HEIGHT))); // Right platform
    
        auto randomPlatforms = Platform::generateRandomPlatforms(WORLD_WIDTH, WORLD_HEIGHT, 200);
        platforms.insert(platforms.end(), randomPlatforms.begin(), randomPlatforms.end());
    }

    void handleEvent(const SDL_Event& event) override
    {
        Input::update(event);

        if (Input::isKeyHeld(SDL_SCANCODE_ESCAPE))
        {
            SDL_Log("Escape key pressed, exiting game.");
            engine->stop();
        }
    }

    void update(float deltaTime) override
    {
        fpsInstance.calc_fps();
        
        player->update(deltaTime);
        enemy->update(player, deltaTime);

        // If somehow the player or enemy goes below the ground level, call intoAbyss which will teleport entity to the ground level
        if (player->getY() > GROUND_LEVEL)
        {
            player->intoAbyss(GROUND_LEVEL);
        }
        if (enemy->getY() > GROUND_LEVEL)
        {
            enemy->intoAbyss(GROUND_LEVEL);
        }

        // Going round the world
        if (player->getX() - player->getWidth() + 20 > WORLD_WIDTH)
        {
            player->setX(0);
        }
        if (enemy->getX() - enemy->getWidth() + 20 > WORLD_WIDTH)
        {
            enemy->setX(0);
        }
        if (player->getX() + player->getWidth() < 0)
        {
            player->setX(WORLD_WIDTH);
        }
        if (enemy->getX() + enemy->getWidth() < 0)
        {
            enemy->setX(WORLD_WIDTH);
        }
    
        camera->follow(player->getX(), player->getY() - player->getHeight() / 2); // Camera follows player
        camera->clampToWorld(WORLD_WIDTH, WORLD_HEIGHT, GROUND_LEVEL, WORLD_HEIGHT); // Clamp camera to world bounds
    }   

    void render(Renderer* renderer) override
    {
        renderer->setDrawColor(255, 255, 255, 255);
        renderer->clearScreen();

        renderer->setCamera(camera);

        for (Platform& platform : platforms)
        {
            platform.render(renderer);

            SDL_Rect platformRect = platform.rect;
            player->checkCollisionWObj(platformRect);
            enemy->checkCollisionWObj(platformRect);
        }

        renderer->renderText("Fps: " + std::to_string(fpsInstance.get_fps()), 10, 10, engine->font, {0, 0, 0, 255});
        renderer->renderText("Player X: " + std::to_string(player->getX()), 10, 30, engine->font, {0, 0, 0, 255});
        renderer->renderText("Player Y: " + std::to_string(player->getY()), 10, 50, engine->font, {0, 0, 0, 255});
        renderer->renderText("Camera getX: " + std::to_string(camera->getX()), 10, 90, engine->font, {0, 0, 0, 255});
        renderer->renderText("Camera getY: " + std::to_string(camera->getY()), 10, 110, engine->font, {0, 0, 0, 255});
    
        renderer->setDrawColor(0, 0, 0, 255);
        player->render(renderer);
        enemy->render(renderer);
    }
};

// Factory function to create game instance
Game* createGameInstance()
{
    return new MyGame();
}
