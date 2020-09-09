#include "MSpaceship.h"

namespace Game {
namespace Model {
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
  auto distance = m_speed * delta_time.asSeconds();
  m_position.x -= distance;
}

void Spaceship::MoveRight(const sf::Time delta_time) {
  auto distance = m_speed * delta_time.asSeconds();
  m_position.x += distance;
}

void Spaceship::MoveTop(const sf::Time delta_time) {
  auto distance = m_speed * delta_time.asSeconds();
  m_position.y -= distance;
}

void Spaceship::MoveDown(const sf::Time delta_time) {
  auto distance = m_speed * delta_time.asSeconds();
  m_position.y += distance;
}
}  // namespace Model
}  // namespace Game
