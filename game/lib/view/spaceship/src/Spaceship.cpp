#include "Spaceship.h"

#include "Assets.h"

namespace Game {
Spaceship::Spaceship() {
  m_sprite.setTexture(Assets::Instance().spaceship);
}

void Spaceship::Update(const Player& player) {
  m_sprite.setPosition(player.GetPositionX(), player.GetPositionY());
}

void Spaceship::Draw(Window& window) {
  window.Draw(m_sprite);
}
}  // namespace Game
