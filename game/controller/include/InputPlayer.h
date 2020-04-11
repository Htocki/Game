#pragma once

#include <SFML/Window/Event.hpp>

#include "Player.h"

namespace Game {
class InputPlayer {
 public:
  void HandleInput(Player& player, sf::Event& event);
};
}  // namespace Game
