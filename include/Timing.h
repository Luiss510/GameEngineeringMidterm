#ifndef TIMING_H
#define TIMING_H

#include "StandardIncludes.h"

class Timing : public Singleton<Timing>
{
public:
    // Constructors/Destructors
    Timing();
    virtual ~Timing() {}

    // Accessors
    unsigned int GetFPS() { return m_fpsLast; }
    float GetDeltaTime() { return m_deltaTime; }
    unsigned int getCurrentTime() { return m_currentTime; }
    // Methods
    void Tick();

private:
    // Members
    unsigned int m_currentTime;
    unsigned int m_lastTime;
    unsigned int m_fpsStart;
    unsigned int m_fpsCount;
    unsigned int m_fpsLast;
    float m_deltaTime;
};

#endif // TIMING_H
