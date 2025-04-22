#include "Fps.hpp"

void Fps::calc_fps()
{
    Uint32 currentTime = SDL_GetTicks();
    m_frameCount++;

    if (currentTime - m_lastTime >= 1000)
    {
        m_fps = m_frameCount;
        m_frameCount = 0;
        m_lastTime = currentTime;
    }
}

int Fps::get_fps() const
{
    return m_fps;
}
