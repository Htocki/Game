#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Assets.h"

namespace Game 
{
    class RenderPlayer
        : sf::Drawable
        , sf::Transformable
    {
    public:
        RenderPlayer();

        virtual void draw(
            sf::RenderTarget& target,
            sf::RenderStates states
        ) const final;

        sf::Sprite spaceship;
    };
}