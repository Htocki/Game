#include "MovingLeftPlayerState.h"

#include <memory>

#include "Player.h"
#include "StandingPlayerState.h"

namespace Game {
void MovingLeftPlayerState::HandleInput(Player& player, const sf::Event& event) {
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        player.SetState(std::make_unique<StandingPlayerState> ());
        break;

      default:
        break;
    }
  } else if (event.type == sf::Event::KeyReleased) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
        player.SetState(std::make_unique<StandingPlayerState> ());
        break;

      default:
        break;
    }
  }
}

void MovingLeftPlayerState::Update(Player& player, const sf::Time delta_time) {
  player.MoveLeft(player.GetSpeed() * delta_time.asSeconds());
}
}  // namespace Game
