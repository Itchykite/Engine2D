#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <random>
#include <ctime>
#include "../Renderer.hpp"

class Platform
{
public:
    SDL_Rect rect;
    std::vector<Platform> platforms;

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

    static std::vector<Platform> generateRandomPlatforms(int WORLD_WIDTH, int WORLD_HEIGHT, int count)
    {
        std::vector<Platform> platforms;

        std::mt19937 mt(static_cast<unsigned>(time(nullptr)));
        std::uniform_int_distribution<int> xDist(50, WORLD_WIDTH - 150);
        std::uniform_int_distribution<int> yDist(0, WORLD_HEIGHT - 100);
        std::uniform_int_distribution<int> wDist(50, 150);

        for (int i = 0; i < count; ++i)
        {
            int x = xDist(mt);
            int y = yDist(mt);
            int width = wDist(mt);

            platforms.emplace_back(x, y, width, 20);
        }

        return platforms;
    }
};
