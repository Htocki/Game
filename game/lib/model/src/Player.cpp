#include "Player.h"

void Game::Player::Update(sf::Time delta_time) {
  switch (m_state) {
    case State::MovingLeft:
      m_position.x -= (m_speed * delta_time.asSeconds());
      break;

    case State::MovingRight:
      m_position.x += (m_speed * delta_time.asSeconds());
      break;

    default:
      break;
  }
}
