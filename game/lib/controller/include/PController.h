#pragma once

#include <SFML/Window/Event.hpp>

#include "Player.h"

namespace Game {
class PController {
 public:
  void HandleInput(Player& player, sf::Event& event);
};
}  // namespace Game
