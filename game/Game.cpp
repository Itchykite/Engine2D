#include "Game.hpp"
#include "../engine/input/InputManager.hpp"
#include "../engine/entity/player/Player.hpp"

#include <string>

class MyGame : public Game
{
private:
    Player* player = nullptr;

public:
    MyGame()
    {
        player = new Player(100, 100, 50, 50);
    }

    ~MyGame()
    {
        delete player;
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
    }

    void render(Renderer* renderer) override
    {
        renderer->setDrawColor(255, 255, 255, 255);
        renderer->clearScreen();

        renderer->renderText("Fps: " + std::to_string(fpsInstance.get_fps()), 10, 10, engine->font, {0, 0, 0, 255});

        renderer->setDrawColor(0, 0, 0, 255);
        player->render(renderer);
    }
};

// Factory function to create game instance
Game* createGameInstance()
{
    return new MyGame();
}
