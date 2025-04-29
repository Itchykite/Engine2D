#include "Engine.hpp"
#include "../../game/Game.hpp"
#include <iostream>
#include <unistd.h>

bool Engine::init(const char* title, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) 
    {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    rendererInstance = new Renderer(renderer);

    //chdir("/home/kacper/cpp/Engine2D");
    font = TTF_OpenFont("assets/fonts/default.ttf", 24);
    if(!font)
    {
        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        return false;
    }

    isRunning = true;
    return true;
}

void Engine::setGame(Game* g)
{
    game = g;
}

void Engine::run()
{
    Uint32 lastTime = SDL_GetTicks();

    while(isRunning)
    {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f; // sekundy
        lastTime = currentTime;

        processEvents();
        update(deltaTime);
        render();
    }
}

void Engine::processEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
       
        game->handleEvent(e);
    }
}

void Engine::update(float deltaTime)
{
    if(game)
    {
        game->update(deltaTime);
    }
}

void Engine::render()
{
    rendererInstance->clearScreen();

    if(game)
    {
        game->render(rendererInstance);
    }

    rendererInstance->presentScreen();
}

void Engine::stop()
{
    SDL_Log("Stopping the engine.");
    isRunning = false;
}

void Engine::shutdown()
{
    SDL_Log("Shutting down the engine.");

    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    if(font) TTF_CloseFont(font);
    if(rendererInstance) delete rendererInstance;
    if(game) delete game;

    TTF_Quit();
    SDL_Quit();
}
