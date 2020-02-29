#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

namespace Game
{
    class InputComponent {
    public:
        void Update(Player& player, sf::Event event);
    };
}