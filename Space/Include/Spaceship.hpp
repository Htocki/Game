#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "ResourceHolder.hpp"



class Spaceship
        : public sf::Drawable
{
public:
    Spaceship (sf::Vector2f);
	void processEvents (sf::Event);
    void update (sf::Time);
    virtual void draw (sf::RenderTarget&, sf::RenderStates) const final;
	void setTexture (sf::Texture&);


private:
	enum class State
	{
		STANDING,
		MOVING_UP,
		MOVING_DOWN,
		MOVING_LEFT,
		MOVING_RIGHT
	};

	State			state_;
	int				frames_;
    sf::Vector2f    position_;
	const float		speed_;
    sf::Sprite		sprite_;
};
