#pragma once

#include <SDL2/SDL.h>
#include "../Renderer.hpp"

class Platform
{
public:
    SDL_Rect rect;

    Platform(int x, int y, int w, int h)
    {
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
    }

    void render(Renderer* renderer)
    {
        renderer->setDrawColor(0, 0, 0, 255);
        renderer->drawCollisonRect(rect.x, rect.y, rect.w, rect.h);
    }
};
