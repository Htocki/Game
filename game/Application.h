#pragma once

#include <SFML/System/Time.hpp>

#include "Engine.h"
#include "View.h"
#include "Controller.h"

namespace Game {
    class Application {
    public:
        Application();

        void Run();

    private:
        Engine m_engine;
        View m_view;
        Controller m_controller;

        const sf::Time m_delay;
    };
}