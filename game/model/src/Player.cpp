#include "Player.h"

void Game::Player::Update(sf::Time deltaTime) {
	switch (m_state)
	{
	case State::Moving_Left:
		m_position.x -= (m_speed * deltaTime.asSeconds());
		break;

	case State::Moving_Right:
		m_position.x += (m_speed * deltaTime.asSeconds());
		break;
	}
}
