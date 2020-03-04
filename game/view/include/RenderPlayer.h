#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Player.h"

namespace Game 
{
    class RenderPlayer
        : sf::Drawable
        , sf::Transformable
    {
    public:
        RenderPlayer();
        void Render(const Player& player, sf::RenderWindow& window);

    private:
        void Update(const Player& player);

        virtual void draw(
            sf::RenderTarget& target,
            sf::RenderStates states
        ) const final;

    private:
        sf::Sprite m_spaceship;
    };
}