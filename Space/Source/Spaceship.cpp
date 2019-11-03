#include "Spaceship.hpp"



Spaceship::Spaceship (sf::Vector2f position) 
	: GameObject(position)
    , state_(State::STANDING)
	, speed_(100.f)
{
    sprite_.setPosition(position);
}


void Spaceship::input (sf::Event event) {
	switch (state_)
	{
    case State::STANDING:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
                state_ = State::MOVING_UP;
				break;

			case sf::Keyboard::Down:
                state_ = State::MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
                state_ = State::MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
                state_ = State::MOVING_RIGHT;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;

    case State::MOVING_UP:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Down:
                state_ = State::MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
                state_ = State::MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
                state_ = State::MOVING_RIGHT;
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
                state_ = State::STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;

    case State::MOVING_DOWN:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
                state_ = State::MOVING_UP;
				break;
				
			case sf::Keyboard::Left:
                state_ = State::MOVING_LEFT;
				break;

			case sf::Keyboard::Right:
                state_ = State::MOVING_RIGHT;
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
                state_ = State::STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;

    case State::MOVING_LEFT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
                state_ = State::MOVING_UP;
				break;

			case sf::Keyboard::Down:
                state_ = State::MOVING_DOWN;
				break;

			case sf::Keyboard::Right:
                state_ = State::MOVING_RIGHT;
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
                state_ = State::STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;

    case State::MOVING_RIGHT:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
                state_ = State::MOVING_UP;
				break;

			case sf::Keyboard::Down:
                state_ = State::MOVING_DOWN;
				break;

			case sf::Keyboard::Left:
                state_ = State::MOVING_LEFT;
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
                state_ = State::STANDING;
				break;

            default:   // Добавлена из-за предупреждения комилиятора.
                ;
			}
		}
		break;
	}
}

void Spaceship::update (sf::Time dt) {
	sf::Vector2f movement(0.f, 0.f);

	switch (state_)
	{
    case State::STANDING :
		movement.y -= speed_;
		break;

    case State::MOVING_DOWN:
		movement.y += speed_;
		break;

    case State::MOVING_LEFT:
		movement.x -= speed_;
		break;

    case State::MOVING_RIGHT:
		movement.x += speed_;
		break;

    default:   // Добавлена из-за предупреждения комилиятора.
        ;
	}

    sprite_.move(movement * dt.asSeconds());
}

void Spaceship::draw (sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite_, states);
}

void Spaceship::setTexture (sf::Texture& texture) {
	sprite_.setTexture(texture);
}
