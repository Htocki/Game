#pragma once

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Observer.h"
#include "RenderPlayer.h"

namespace Game
{
    class View 
        : Observer
    {
    public:
        View(Engine* engine);
        virtual void OnNotify() final;
        
    private:
        Engine* m_engine;
        RenderPlayer m_player;

        sf::RenderWindow& m_window;
    };
}