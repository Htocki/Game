#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Drawable.h"
#include "Positionable.h"
#include "Window.h"

namespace Game::View {
class Spaceship : public Drawable {
 public:
  Spaceship(const Positionable& positionable);
  void Draw(Window& window) final;

 private:
  void Update();

  const Positionable& m_positionable;
  sf::Sprite m_sprite;
};
}  // namespace Game::View
