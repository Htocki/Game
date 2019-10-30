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
                    Spaceship(sf::Vector2f);
	void			processEvents(sf::Event event);
    void            update(sf::Time dt);
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	void			setTexture(sf::Texture& texture);


private:
	enum State
	{
		STATE_STANDING,
		STATE_MOVING_UP,
		STATE_MOVING_DOWN,
		STATE_MOVING_LEFT,
		STATE_MOVING_RIGHT
	};

	State			state_;
	int				frames_;
    sf::Vector2f    position_;
	const float		speed_;
    sf::Sprite		sprite_;
};
