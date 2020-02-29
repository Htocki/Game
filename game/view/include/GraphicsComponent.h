#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Assets.h"

namespace Game 
{
    class GraphicsComponent
        : sf::Drawable
        , sf::Transformable
    {
    public:
        GraphicsComponent();

        void Update(sf::RenderWindow& window);

    private:
        virtual void draw(
            sf::RenderTarget& target,
            sf::RenderStates states
        ) const final;

        sf::Sprite spaceship;
    };
}