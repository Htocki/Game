#pragma once

#include <string>

#include <SFML/System.hpp>

#include "Assets.h"

namespace Game
{
    class Player {
    public:
        enum class State {
            Standing,
            Moving_Up,
            Moving_Down,
            Moving_Left,
            Moving_Right
        };

        Player() = default;

        auto GetName() const ->std::string { return m_name; }
        auto GetPosition() const ->sf::Vector2f { return m_position; }
        auto GetState() const ->State { return m_state; };

        void SetName(std::string name) { m_name = name; }
        void SetPosition(sf::Vector2f position) { m_position = position; }
        void SetState(State state) { m_state = state; }

        void Update(sf::Time deltaTime);

    private:
        std::string m_name = { "Unnamed" };
        sf::Vector2f m_position = { 100.f, 100.f };
        float m_speed = { 400.f };
        State m_state = { State::Standing };
    };
}