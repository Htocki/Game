#include "Positioned.h"

namespace Game {
Positioned::Positioned() {
  m_position.x = 0.f;
  m_position.y = 0.f;
}

Positioned::Positioned(Position position)
    : m_position { position }
{}

Positioned::Positioned(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void Positioned::SetPosition(Position position) {
  m_position = position;
}

void Positioned::SetPosition(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void Positioned::SetPositionX(float x) {
  m_position.x = x;
}

void Positioned::SetPositionY(float y) {
  m_position.y = y;
}

Position Positioned::GetPosition() const {
  return m_position;
}

float Positioned::GetPositionX() const {
  return m_position.x;
}

float Positioned::GetPositionY() const {
  return m_position.y;
}
}  // namespace Game
