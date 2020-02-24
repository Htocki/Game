#include "Spaceship.h"

Spaceship::Spaceship(sf::Vector2f position)
	: Object(position)
	, speed_(100.f)
{
	sprite_.setPosition(position);
}

void Spaceship::moveLeft(sf::Time time) {
	position_.x -= (speed_ * time.asSeconds());
	sprite_.setPosition(position_);
}

void Spaceship::moveRight(sf::Time time) {
	position_.x += (speed_ * time.asSeconds());
	sprite_.setPosition(position_);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite_, states);
}

float Spaceship::getSpeed() const {
	return speed_;
}

void Spaceship::setTexture(sf::Texture& texture) {
	sprite_.setTexture(texture);
}
