#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Fps
{
public:
    Fps() = default;
    
    void calc_fps();
    int get_fps() const;

private:
    Uint32 m_lastTime = 0;
    Uint32 m_frameCount = 0;
    int m_fps = 0;
};
