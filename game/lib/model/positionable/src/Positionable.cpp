#include "Positionable.h"

namespace Game {
Positionable::Positionable() {
  m_position.x = 0.f;
  m_position.y = 0.f;
}

Positionable::Positionable(Position position)
    : m_position { position }
{}

Positionable::Positionable(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void Positionable::SetPosition(Position position) {
  m_position = position;
}

void Positionable::SetPosition(float x, float y) {
  m_position.x = x;
  m_position.y = y;
}

void Positionable::SetPositionX(float x) {
  m_position.x = x;
}

void Positionable::SetPositionY(float y) {
  m_position.y = y;
}

Position Positionable::GetPosition() const {
  return m_position;
}

float Positionable::GetPositionX() const {
  return m_position.x;
}

float Positionable::GetPositionY() const {
  return m_position.y;
}
}  // namespace Game
