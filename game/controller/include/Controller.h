#pragma once

#include <SFML/Graphics.hpp>

#include "InputPlayer.h"
#include "Engine.h"
#include "Observable.h"

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