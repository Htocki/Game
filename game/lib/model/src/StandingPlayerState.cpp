#include "StandingPlayerState.h"

#include <memory>

#include "MovingLeftPlayerState.h"
#include "MovingRightPlayerState.h"
#include "Player.h"

namespace Game {
std::unique_ptr<PlayerState> StandingPlayerState::HandleInput(Player& player, const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
        return std::make_unique<MovingLeftPlayerState> ();
        break;

      case sf::Keyboard::Right:
        return std::make_unique<MovingRightPlayerState> ();
        break;

      default:
        break;
    }
  }
  return std::make_unique<StandingPlayerState> ();
}

void StandingPlayerState::Update(Player& player, const sf::Time delta_time) {}
}  // namespace Game
