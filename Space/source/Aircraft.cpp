#include "Aircraft.hpp"



Aircraft::Aircraft()
	: state_(STATE_STANDING)
	, frames_(0)
	, speed_(100.f)
{
	sprite_.setPosition(100.f, 100.f);
}

void Aircraft::processEvents(sf::Event event)
{
	switch (state_)
	{
	case STATE_STANDING:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_MOVING_UP;
				break;

			case sf::Keyboard::Down:
				state_ = STATE_MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
				state_ = STATE_MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
				state_ = STATE_MOVING_RIGHT;
				break;
			}
		}
		break;

	case STATE_MOVING_UP:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Down:
				state_ = STATE_MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
				state_ = STATE_MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
				state_ = STATE_MOVING_RIGHT;
				break;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_STANDING;
				break;
			}
		}
		break;

	case STATE_MOVING_DOWN:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_MOVING_UP;
				break;
				
			case sf::Keyboard::Left:
				state_ = STATE_MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
				state_ = STATE_MOVING_RIGHT;
				break;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Down:
				state_ = STATE_STANDING;
				break;
			}
		}
		break;

	case STATE_MOVING_LEFT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_MOVING_UP;
				break;

			case sf::Keyboard::Down:
				state_ = STATE_MOVING_DOWN;
				break;

			case sf::Keyboard::Right:
				state_ = STATE_MOVING_RIGHT;
				break;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state_ = STATE_STANDING;
				break;
			}
		}
		break;

	case STATE_MOVING_RIGHT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_MOVING_UP;
				break;

			case sf::Keyboard::Down:
				state_ = STATE_MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
				state_ = STATE_MOVING_LEFT;
				break;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				state_ = STATE_STANDING;
				break;
			}
		}
		break;
	}
}

void Aircraft::update(sf::Time delay)
{
	sf::Vector2f movement(0.f, 0.f);

	switch (state_)
	{
	case STATE_MOVING_UP:
		movement.y -= speed_;
		break;

	case STATE_MOVING_DOWN:
		movement.y += speed_;
		break;

	case STATE_MOVING_LEFT:
		movement.x -= speed_;
		break;

	case STATE_MOVING_RIGHT:
		movement.x += speed_;
		break;
	}

	sprite_.move(movement * delay.asSeconds());
}

sf::Sprite Aircraft::getSprite() const
{
	return sprite_;
}

void Aircraft::setTexture(sf::Texture& texture)
{
	sprite_.setTexture(texture);
}