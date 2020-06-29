#include "Spaceship.h"

#include "Assets.h"

namespace Game {
Spaceship::Spaceship() {
  m_sprite.setTexture(Assets::Instance().spaceship);
}

void Spaceship::Draw(const Player& player, sf::RenderWindow& window) {
  m_sprite.setPosition(player.GetPosition());
  window.draw(m_sprite);
}
}  // namespace Game
