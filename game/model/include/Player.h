#pragma once

#include <string>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Enums.h"
#include "Spaceship.h"

class Player
{
public:
    Player (ResourceHolder <sf::Texture, Textures::ID>&);

    void input (sf::Event);
    void update (sf::Time);
    void draw (sf::RenderTarget&, sf::RenderStates) const;
    
	int			getScore() const;
    std::string getName() const;

private:
	enum class State {
		STANDING,
		MOVING_UP,
		MOVING_DOWN,
		MOVING_LEFT,
		MOVING_RIGHT
	};

	State		state_;
    Spaceship	spaceship_;
	int			score_;
    std::string name_;
};
