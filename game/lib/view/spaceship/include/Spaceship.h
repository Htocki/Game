#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Observer.h"
#include "Player.h"
#include "Window.h"

namespace Game {
class Spaceship : public Observer {
 public:
  Spaceship();
  void Update(const Player& player);
  void Draw(Window& window) final;

 private:
  sf::Sprite m_sprite;
};
}  // namespace Game
