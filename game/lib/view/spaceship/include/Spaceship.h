#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Player.h"
#include "Window.h"

namespace Game {
class Spaceship {
 public:
  Spaceship();
  void Draw(const Player& player, Window& window);

 private:
  sf::Sprite m_sprite;
};
}  // namespace Game
