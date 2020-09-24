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
  SetPositionX(GetPositionX() - m_speed);
}

void Spaceship::MoveRight() {
  SetPositionX(GetPositionX() + m_speed);
}

void Spaceship::MoveUp() {
  SetPositionY(GetPositionY() - m_speed);
}

void Spaceship::MoveDown() {
  SetPositionY(GetPositionY() + m_speed);
}
}  // namespace Game::Model
