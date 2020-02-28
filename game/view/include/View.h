#pragma once

#include <SFML/Graphics.hpp>

#include "Model.h"

namespace Game
{
    class View 
        : sf::Drawable
        , sf::Transformable
    {
    public:
        View(Model* model);
        void Render();

    private:
        virtual void draw(
            sf::RenderTarget& target, 
            sf::RenderStates states
        ) const final;

        Model* m_model;
    };
}