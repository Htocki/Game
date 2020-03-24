#include "InputPlayer.h"

#include <SFML/Window/Keyboard.hpp>

void Game::InputPlayer::HandleInput(
	Player& player, 
	const sf::Event& event
) {
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

			default:
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
			
			default:
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

			default:
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

			default:
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

			default:
				break;
			}
		}
		break;

	default:
		break;
	}
}