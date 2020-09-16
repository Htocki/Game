#include "VSpaceship.h"

#include "Assets.h"

namespace Game::View {
Spaceship::Spaceship(const Positionable& positionable) 
    : m_positionable { positionable }
{
  m_sprite.setTexture(Assets::Instance().GetSpaceshipTexture());
}

void Spaceship::Update() {
  m_sprite.setPosition(
    m_positionable.GetPositionX(), 
    m_positionable.GetPositionY());
}

void Spaceship::DrawOnWindow(Window* window) {
  Update();
  window->DrawEntity(m_sprite);
}
}  // namespace Game::View
