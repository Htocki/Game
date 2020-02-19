#include "Spaceship.h"

Spaceship::Spaceship(sf::Vector2f position)
	: Object(position)
	, speed(100.f)
{
	sprite.setPosition(position);
}

void Spaceship::moveLeft(sf::Time time) {
	position.x -= (speed * time.asSeconds());
	sprite.setPosition(position);
}

void Spaceship::moveRight(sf::Time time) {
	position.x += (speed * time.asSeconds());
	sprite.setPosition(position);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

float Spaceship::getSpeed() const {
	return speed;
}

void Spaceship::setTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
}
