#pragma once

class Game; //inicjalizacja przed

class Engine
{
public:
    bool init(const char* title, int width, int height);
    void run();
    void shutdown();
    void setGame(Game* g);

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;
    Game* game;

    void processEvents();
    void update();
    void render();
}
