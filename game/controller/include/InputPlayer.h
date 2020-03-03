#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

namespace Game
{
    class InputPlayer {
    public:
        void HandleInput(Player& player, sf::Event event);
    };
}