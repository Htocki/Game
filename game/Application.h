#pragma once

#include <SFML/System/Time.hpp>

#include "Model.h"
#include "View.h"
#include "Controller.h"

namespace Game {
    class Application {
    public:
        Application();

        void Run();

    private:
        Model m_model;
        View m_view;
        Controller m_controller;

        const sf::Time m_delay;
    };
}