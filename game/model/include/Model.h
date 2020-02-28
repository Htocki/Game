#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.h"

namespace Game 
{
    class Model {
    public:
        enum class State {
            GameOver,
            Loading,
            Menu,
            Pause,
            Records,
            Run,
            Settings
        };

        Model();

        auto GetState() const -> State { return m_state; }
        auto Window() -> sf::RenderWindow& { return m_window; }

    private:
        State m_state;
        sf::RenderWindow m_window;
    };
}