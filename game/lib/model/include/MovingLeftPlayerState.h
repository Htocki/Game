#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "PlayerState.h"

namespace Game {
class MovingLeftPlayerState : public PlayerState {
 public:
  ~MovingLeftPlayerState() override = default;
  void HandleInput(Player& player, const sf::Event& event) final;
  void Update(Player& player, const sf::Time delta_time) final;
};
}  // namespace Game
