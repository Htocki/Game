#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Positionable.h"
#include "Window.h"

namespace Game::View {
class Spaceship {
 public:
  Spaceship(Window* window, const Positionable& positionable);
  void Draw();

 private:
  Window* m_window;
  const Positionable& m_positionable;
  sf::Sprite m_sprite;
};
}  // namespace Game::View
