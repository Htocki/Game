#pragma once

#include <SFML/Window/Event.hpp>

#include "PController.h"
#include "Engine.h"

namespace Game {
class Controller {
 public:
  explicit Controller(Engine* engine);
  void HandleInput(const sf::Event& event);

 private:
  Engine* m_engine;
  PController m_player;
};
}  // namespace Game
