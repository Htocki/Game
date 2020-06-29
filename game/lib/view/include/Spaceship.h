#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Player.h"

namespace Game {
class Spaceship {
 public:
  Spaceship();
  void Draw(const Player& player, sf::RenderWindow& window);

 private:
  sf::Sprite m_sprite;
};
}  // namespace Game
