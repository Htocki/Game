#include "Spaceship.h"

#include "Assets.h"

namespace Game {
Spaceship::Spaceship() {
  m_sprite.setTexture(Assets::Instance().spaceship);
}

void Spaceship::Draw(const Player& player, Window& window) {
  m_sprite.setPosition(player.GetPosition());
  window.Draw(m_sprite);
}
}  // namespace Game
