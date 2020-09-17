#include "MSpaceship.h"

#include <iostream>

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

void Spaceship::MoveLeft() {
  m_position.x -= m_speed;
}

void Spaceship::MoveRight() {
  m_position.x += m_speed;
}

void Spaceship::MoveUp() {
  m_position.y -= m_speed;
}

void Spaceship::MoveDown() {
  m_position.y += m_speed;
}
}  // namespace Game::Model
