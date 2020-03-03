#pragma once

#include <SFML/Graphics.hpp>

#include "Model.h"
#include "Observer.h"
#include "RenderPlayer.h"

namespace Game
{
    class View 
        : sf::Drawable
        , sf::Transformable
        , Observer
    {
    public:
        View(Model* model);
        virtual void OnNotify() final;
        
    private:
        virtual void draw(
            sf::RenderTarget& target, 
            sf::RenderStates states
        ) const final;

        Model* m_model;
        RenderPlayer m_player;
    };
}