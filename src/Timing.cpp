#include "../../Lab5-part-7---Graphics-Core-2-main/include/Timing.h"

Timing::Timing()
{
    m_fpsCount = 0;
    m_fpsLast = 0;
    m_deltaTime = 0;
    m_currentTime = SDL_GetTicks();
    m_lastTime = m_currentTime;
    m_fpsStart = m_currentTime;
}

void Timing::Tick()
{
    m_currentTime = SDL_GetTicks();
    m_deltaTime = (float)(m_currentTime - m_lastTime) / 1000.0f;
    if (m_fpsStart + 1000 <= m_currentTime)
    {
        m_fpsLast = m_fpsCount;
        m_fpsCount = 0;
        m_fpsStart = m_currentTime;
    }
    else
    {
        m_fpsCount++;
    }

    m_lastTime = m_currentTime;
}
