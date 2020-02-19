#include "Player.h"

Player::Player(ResourceHolder <sf::Texture, Textures::ID>& textures)
	: state(State::STANDING)
	, spaceship({ 200, 600 })
	, score(0)
	, name("Miha default player")
{
	spaceship.setTexture(textures.get(Textures::ID::Spaceship));
}

void Player::input(sf::Event event) {
	switch (state)
	{
	case State::STANDING:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state = State::MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
				state = State::MOVING_RIGHT;
				break;
			}
		}
		break;

	case State::MOVING_LEFT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				state = State::MOVING_RIGHT;
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state = State::STANDING;
				break;
			}
		}
		break;

	case State::MOVING_RIGHT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state = State::MOVING_LEFT;
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				state = State::STANDING;
				break;
			}
		}
		break;
	}
}

void Player::update(sf::Time time) {
	// Spaceship update
	switch (state)
	{
	case State::MOVING_LEFT:
		spaceship.moveLeft(time);
		break;

	case State::MOVING_RIGHT:
		spaceship.moveRight(time);
		break;
	}

	// Score update
	score += static_cast<int> (spaceship.getSpeed() * time.asSeconds());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	spaceship.draw(target, states);
}

sf::Int64 Player::getScore() const {
	return score;
}

std::string Player::getName() const {
	return name;
}
