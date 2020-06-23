#include "Player.h"

void Game::Player::Update(sf::Time delta_time) {
  switch (m_state) {
    case State::Moving_Left:
      m_position.x -= (m_speed * delta_time.asSeconds());
      break;

    case State::Moving_Right:
      m_position.x += (m_speed * delta_time.asSeconds());
      break;

    default:
      break;
  }
}
