#include "StandingPlayerState.h"

#include <memory>

#include "MovingLeftPlayerState.h"
#include "MovingRightPlayerState.h"
#include "Player.h"

namespace Game {
void StandingPlayerState::HandleInput(Player& player, const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
        player.SetState(std::make_unique<MovingLeftPlayerState> ());
        break;

      case sf::Keyboard::Right:
        player.SetState(std::make_unique<MovingRightPlayerState> ());
        break;

      default:
        break;
    }
  }
}

void StandingPlayerState::Update(Player& player, const sf::Time delta_time) {}
}  // namespace Game
