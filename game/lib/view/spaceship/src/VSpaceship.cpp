#include "VSpaceship.h"

#include "Assets.h"

namespace Game {
namespace View {
Spaceship::Spaceship() {
  m_sprite.setTexture(Assets::Instance().spaceship);
}

void Spaceship::Link(const Positionable* positionable) {
  m_positionable = positionable;
}

void Spaceship::Update() {
  m_sprite.setPosition(
    m_positionable->GetPositionX(), 
    m_positionable->GetPositionY());
}

void Spaceship::Draw(Window& window) {
  Update();
  window.Draw(m_sprite);
}
}  // namespace View
}  // namespace Game
