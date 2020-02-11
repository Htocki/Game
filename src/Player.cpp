#include "Player.hpp"
#include "Enums.hpp"



Player::Player(ResourceHolder <sf::Texture, Textures::ID>& textures)
	: state_(State::STANDING)
    , spaceship_({200, 600})
	, score_(0)
    , name_("Miha default player")
{
    spaceship_.setTexture(textures.get(Textures::ID::Spaceship));
}

void Player::input (sf::Event event) {
	switch (state_)
	{
	case State::STANDING:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state_ = State::MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
				state_ = State::MOVING_RIGHT;
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
				state_ = State::MOVING_RIGHT;
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state_ = State::STANDING;
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
				state_ = State::MOVING_LEFT;
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				state_ = State::STANDING;
				break;
			}
		}
		break;
	}
}

void Player::update (sf::Time time) {
	// Spaceship update
	switch (state_)
	{
	case State::MOVING_LEFT:
		spaceship_.moveLeft(time);
		break;

	case State::MOVING_RIGHT:
		spaceship_.moveRight(time);
		break;
	}

	// Score update
	score_ += static_cast<int> (spaceship_.getSpeed() * time.asSeconds());
}

void Player::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    spaceship_.draw(target, states);
}

int Player::getScore() const {
    return score_;
}

std::string Player::getName () const {
    return name_;
}
