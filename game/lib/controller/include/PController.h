#pragma once

#include <SFML/Window/Event.hpp>

#include "Player.h"

namespace Game {
class PController {
 public:
  explicit PController(Player& player);
  void HandleInput(const sf::Event& event);

 public:
  Player& m_player;
};
}  // namespace Game
