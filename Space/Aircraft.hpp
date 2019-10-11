#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"



class Aircraft
{
public:
					Aircraft();
	void			processEvents(sf::Event event);
	virtual void	update(sf::Time delay);
	sf::Sprite		getSprite() const;
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
	sf::Sprite		sprite_;
	int				frames_;
	const float		speed_;
};