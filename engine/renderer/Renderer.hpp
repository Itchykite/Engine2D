#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Renderer
{
public:
    Renderer(SDL_Renderer* sdlRenderer);
    ~Renderer();

    void clearScreen();
    void presentScreen();
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void drawRect(int x, int y, int width, int height);
    void renderText(const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);

private:
    SDL_Renderer* renderer;
};

