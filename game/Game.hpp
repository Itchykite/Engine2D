#pragma once

class Game
{
public:
    virtual ~Game() = default;
    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};
