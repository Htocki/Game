#include "Player.h"

namespace Game {
Player::Player()
    : m_name { "Unnamed" }
{
  spaceship.SetPosition(100.f, 100.f);
  spaceship.SetSpeed(300.f);
}

void Player::SetName(std::string name) {
  m_name = name;
}

std::string Player::GetName() const {
  return m_name;
}

void Player::HandleInput(const sf::Event& event, const sf::Time delta_time) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        spaceship.MoveRight(delta_time);
        break;
      case sf::Keyboard::Left:
        spaceship.MoveLeft(delta_time);
        break;
      case sf::Keyboard::Up:
        spaceship.MoveUp(delta_time);
        break;
      case sf::Keyboard::Down:
        spaceship.MoveDown(delta_time);
        break;
      default:
        break;
    }
  }
}
}  // namespace Game
