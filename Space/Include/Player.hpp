#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>

#include <string>

#include "Graphics/Label.hpp"
#include "Spaceship.hpp"
#include "Score.hpp"



class Player
{
public:
    Player (ResourceHolder <sf::Texture, Textures::ID>&);

    void input (sf::Event);
    void update (sf::Time);
    void draw (sf::RenderTarget&, sf::RenderStates) const;
    
    sf::Int64   getScore();
    std::string getName() const;

private:
    Score score_;
    Spaceship spaceship_;
    std::string name_;
};


