#include "MSpaceship.h"

namespace {
  auto Distance(const auto speed, const auto delta_time) {
    return speed * delta_time.asSeconds();
  }
} // namespace

namespace Game::Model {
Spaceship::Spaceship()
    : m_speed { 0.f }
{}

void Spaceship::SetSpeed(float speed) {
  m_speed = speed;
}

float Spaceship::GetSpeed() const {
  return m_speed;
}

void Spaceship::MoveLeft(const sf::Time delta_time) {
  m_position.x -= Distance(m_speed, delta_time);
}

void Spaceship::MoveRight(const sf::Time delta_time) {
  m_position.x += Distance(m_speed, delta_time);
}

void Spaceship::MoveUp(const sf::Time delta_time) {
  m_position.y -= Distance(m_speed, delta_time);
}

void Spaceship::MoveDown(const sf::Time delta_time) {
  m_position.y += Distance(m_speed, delta_time);
}
}  // namespace Game::Model
