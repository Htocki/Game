#pragma once

#include <SFML/Window/Event.hpp>

#include "Player.h"

namespace Game {
class InputPlayer {
 public:
  void HandleInput(Player& player, const sf::Event& event);
};
}  // namespace Game
