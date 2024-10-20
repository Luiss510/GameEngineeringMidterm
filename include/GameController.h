#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "BasicStructs.h"

#include <SDL.h>

class GameController : public Singleton<GameController> {
public:
    // Constructors/Destructors
    GameController();
    virtual ~GameController();

    // Methods
    void RunGame();

private:
    // Members
    SDL_Event m_sdlEvent;
};

#endif // GAME_CONTROLLER_H
