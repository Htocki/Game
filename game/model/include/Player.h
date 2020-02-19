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
	explicit Player(ResourceHolder <sf::Texture, Textures::ID>&);

	void input(sf::Event);
	void update(sf::Time);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::Int64 getScore() const;
	std::string getName() const;
  
private:
	enum class State {
		STANDING,
		MOVING_UP,
		MOVING_DOWN,
		MOVING_LEFT,
		MOVING_RIGHT
	};

	State state;
	Spaceship spaceship;
	sf::Int64 score;
	std::string name;
};