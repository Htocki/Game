#include "InputComponent.h"

void Game::InputComponent::Update(Player& player, sf::Event event) {
	switch (player.GetState())
	{
	case Player::State::Standing:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				player.SetState(Player::State::Moving_Left);
				break;

			case sf::Keyboard::Right:
				player.SetState(Player::State::Moving_Right);
				break;
			}
		}
		break;

	case Player::State::Moving_Left:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				player.SetState(Player::State::Moving_Right);
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				player.SetState(Player::State::Standing);
				break;
			}
		}
		break;

	case Player::State::Moving_Right:
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				player.SetState(Player::State::Moving_Left);
				break;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Right:
				player.SetState(Player::State::Standing);
				break;
			}
		}
		break;
	}
}