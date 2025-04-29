#pragma once

#include "../engine/core/Engine.hpp"
#include "../engine/fps/Fps.hpp"

#include <SDL2/SDL.h>

class Game
{
protected:
    Engine* engine = nullptr;
    Renderer* rendererInstance = nullptr;
    Fps fpsInstance;

public:

    void setEngine(Engine* engine)
    {
        this->engine = engine;
    }

    virtual ~Game() = default;
    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(Renderer* renderer) = 0;
};
