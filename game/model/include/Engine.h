#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Observable.h"
#include "Player.h"

#include "Observable.h"

namespace Game 
{
    class Engine
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

        Engine();

        auto GetState() const -> State { return m_state; }
        auto GetPlayer() const -> Player { return m_player; }

        void SetState(State state) { m_state = state; }


        auto PlayerRef()->Player&;
        auto WindowRef() -> sf::RenderWindow& { return m_window; }

        bool PollEvent(sf::Event& event);
        void Update(sf::Time deltaTime);
        void Stop();

        bool IsRuning() const;

    private:
        Player m_player;
        State m_state;
        sf::RenderWindow m_window;
    };
}