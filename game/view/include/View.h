#pragma once

#include <SFML/Graphics.hpp>

#include "Model.h"
#include "Observer.h"

namespace Game
{
    class View 
        : sf::Drawable
        , sf::Transformable
        , Observer
    {
    public:
        View(Model* model);
        virtual void Update() final;

    private:
        virtual void draw(
            sf::RenderTarget& target, 
            sf::RenderStates states
        ) const final;

        Model* m_model;
    };
}