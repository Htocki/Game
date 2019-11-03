#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "ResourceHolder.hpp"
#include "GameObject.hpp"



class Spaceship : public GameObject
{
public:
    Spaceship (sf::Vector2f);

	virtual void input (sf::Event) final;
    virtual void update (sf::Time) final;
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
	const float		speed_;
    sf::Sprite		sprite_;
};
