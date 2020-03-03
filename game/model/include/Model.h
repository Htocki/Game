#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Observable.h"
#include "Player.h"

#include "Observable.h"

namespace Game 
{
    class Model 
        : public Observable
    {
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

        void SetState(State state) { m_state = state; }

        auto WindowRef()->sf::RenderWindow&;
        auto PlayerRef()->Player&;

        void Update(sf::Time deltaTime);



    private:
        Player m_player;
        State m_state;
        sf::RenderWindow m_window;
    };
}