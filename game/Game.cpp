#include "Game.hpp"
#include "../engine/input/InputManager.hpp"
#include <string>

class MyGame : public Game
{
private:

public:
    void handleEvent(const SDL_Event& event) override 
    {
        Input::update(event);
  
        if (Input::isKeyPressed(SDLK_ESCAPE))
        {
            SDL_Log("Escape key pressed, exiting game.");
            engine->stop();
        }
    }

    void update() override 
    {
        fpsInstance.calc_fps();
    }

    void render(Renderer* renderer) override
    {
        renderer->renderText("Fps: " + std::to_string(fpsInstance.get_fps()), 10, 10, engine->font, {255, 255, 255, 255});
    }
};

// Factory function to create game instance
Game* createGameInstance()
{
    return new MyGame();
}
