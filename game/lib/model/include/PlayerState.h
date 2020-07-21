#pragma once

#include <utility>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

namespace Game {
class Player;

class PlayerState {
 public:
  virtual ~PlayerState() = default;
  virtual std::unique_ptr<PlayerState> HandleInput(Player& player, const sf::Event& event) = 0;
  virtual void Update(Player& player, const sf::Time delta_time) = 0;
};
}  // namespace Game
