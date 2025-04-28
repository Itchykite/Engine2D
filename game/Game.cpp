#include "Game.hpp"
#include "../engine/input/InputManager.hpp"
#include "../engine/entity/player/Player.hpp"
#include "../engine/entity/enemy/Enemy.hpp"
#include "../engine/entity/movementStrategy/simpleFollowStrategy/SimpleFollowStrategy.hpp"

#include <string>
#include <iostream>

class MyGame : public Game
{
private:
    SimpleFollowStrategy* followStrategy = nullptr; 
    Player* player = nullptr;
    Enemy* enemy = nullptr;
    

public:
    MyGame()
    {
        followStrategy = new SimpleFollowStrategy();

        player = new Player(100, 100, 50, 50);
        enemy = new Enemy(200, 200, 50, 50, followStrategy);

    }

    ~MyGame()
    {
        delete player;
        delete enemy;
        delete followStrategy;              
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

    void update() override
    {
        fpsInstance.calc_fps();
        
        player->update();
        enemy->update(player);
    }

    void render(Renderer* renderer) override
    {
        renderer->setDrawColor(255, 255, 255, 255);
        renderer->clearScreen();

        renderer->renderText("Fps: " + std::to_string(fpsInstance.get_fps()), 10, 10, engine->font, {0, 0, 0, 255});

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
