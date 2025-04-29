#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../renderer/Renderer.hpp"

class Game; //inicjalizacja przed

class Engine
{
public:
    bool init(const char* title, int width, int height);
    void run();
    void shutdown();
    void setGame(Game* g);
    void stop();

    TTF_Font* font = nullptr;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    Renderer* rendererInstance = nullptr;
    bool isRunning = false;
    Game* game = nullptr;

    void processEvents();
    void update(float deltaTime);
    void render();
};
