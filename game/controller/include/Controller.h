#pragma once

#include <SFML/Graphics.hpp>

#include "Model.h"

namespace Game
{
    class Controller {
    public:
        Controller(Model* model);
        void Run();

    private:
        Model* m_model;
    };
}