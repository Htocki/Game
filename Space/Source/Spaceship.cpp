#include "Spaceship.hpp"



Spaceship::Spaceship(sf::Vector2f position)
	: state_(STATE_STANDING)
	, frames_(0)
    , position_(position)
	, speed_(100.f)
{
    sprite_.setPosition(position_);
}


void Spaceship::processEvents(sf::Event event)
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

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
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

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				state_ = STATE_STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
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

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Down:
				state_ = STATE_STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
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

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				state_ = STATE_STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
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

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		} 
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				state_ = STATE_STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;
	}
}

void Spaceship::update(sf::Time dt)
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

    default:   // Добавлена из-за предупреждения комилиятора.
        ;
	}

    sprite_.move(movement * dt.asSeconds());
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite_, states);
}

void Spaceship::setTexture(sf::Texture& texture)
{
	sprite_.setTexture(texture);
}
