#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>

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
	sf::View	getView() const;

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
	Score		score_;
    std::string name_;
	sf::View	view_;
};


