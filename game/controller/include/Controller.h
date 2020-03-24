#pragma once

#include "InputPlayer.h"
#include "Engine.h"

namespace Game
{
    class Controller {
    public:
        Controller(Engine* engine);
        void HandleInput();

    private:
        Engine* m_engine;
        InputPlayer m_player;
    };
}