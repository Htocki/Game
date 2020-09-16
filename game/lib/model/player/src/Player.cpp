#include "Player.h"

namespace Game {
Player::Player()
    : m_name { "Unnamed" }
{
  m_spaceship.SetPosition(100.f, 100.f);
  m_spaceship.SetSpeed(300.f);
}

void Player::SetName(std::string name) {
  m_name = name;
}

std::string Player::GetName() const {
  return m_name;
}

const Model::Spaceship& Player::GetSpaceship() const {
  return m_spaceship;
}

void Player::HandleEvent(const sf::Event& event, const sf::Time delta_time) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        m_spaceship.MoveRight(delta_time);
        break;
      case sf::Keyboard::Left:
        m_spaceship.MoveLeft(delta_time);
        break;
      case sf::Keyboard::Up:
        m_spaceship.MoveUp(delta_time);
        break;
      case sf::Keyboard::Down:
        m_spaceship.MoveDown(delta_time);
        break;
      default:
        break;
    }
  }
}
}  // namespace Game
