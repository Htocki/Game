#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Engine.h"
#include "Observer.h"
#include "PRender.h"

namespace Game {
class Render : public Observer {
 public:
  explicit Render(Engine* engine);
  void Update() final;

 private:
  Engine* m_engine;
  PRender m_player;

  sf::RenderWindow& m_window;
};
}  // namespace Game
