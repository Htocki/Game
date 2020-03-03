#pragma once

#include <SFML/Graphics.hpp>

#include "InputPlayer.h"
#include "Model.h"
#include "Observable.h"

namespace Game
{
    class Controller {
    public:
        Controller(Model* model);
        void HandleInput();

    private:
        Model* m_model;

        InputPlayer m_player;
    };
}