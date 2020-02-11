#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "ResourceHolder.hpp"
#include "GameObject.hpp"



class Spaceship : public GameObject
{
public:
    Spaceship (sf::Vector2f);

    virtual void draw (sf::RenderTarget&, sf::RenderStates) const final;

	void moveLeft(sf::Time);
	void moveRight(sf::Time);

	float getSpeed() const;

	void setTexture (sf::Texture&);


private:
	float		speed_;
    sf::Sprite	sprite_;
};
