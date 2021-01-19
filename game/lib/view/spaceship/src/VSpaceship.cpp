#include "VSpaceship.h"

#include "Assets.h"

namespace Game::View {
Spaceship::Spaceship(Window* window, const Positionable& positionable) 
    : m_window { window }
    , m_positionable { positionable }
{
  m_sprite.setTexture(Assets::Instance().GetSpaceshipTexture());
}

void Spaceship::Draw() {
  m_sprite.setPosition(
    m_positionable.GetPositionX(), 
    m_positionable.GetPositionY());
  m_window->Draw(m_sprite);
}
}  // namespace Game::View
