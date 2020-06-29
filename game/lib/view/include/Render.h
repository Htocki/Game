#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Engine.h"
#include "Observer.h"
#include "Spaceship.h"

namespace Game {
class Render : public Observer {
 public:
  explicit Render(Engine* engine);
  void Draw() final;

 private:
  Engine* m_engine;
  Spaceship m_spaceship;

  sf::RenderWindow& m_window;
};
}  // namespace Game
