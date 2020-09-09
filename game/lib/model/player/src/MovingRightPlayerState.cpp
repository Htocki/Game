#include "MovingRightPlayerState.h"

#include <memory>

#include "MovingLeftPlayerState.h"
#include "Player.h"
#include "StandingPlayerState.h"

namespace Game {
std::unique_ptr<PlayerState> MovingRightPlayerState::HandleInput(Player& player, const sf::Event& event){
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code) {
      case sf::Keyboard::Left:
        return std::make_unique<MovingLeftPlayerState> ();
        break;

      default:
        break;
    }
  } else if (event.type == sf::Event::KeyReleased) {
    switch (event.key.code) {
      case sf::Keyboard::Right:
        return std::make_unique<StandingPlayerState> ();
        break;

      default:
        break;
    }
  }
  return std::make_unique<MovingRightPlayerState> ();
}

void MovingRightPlayerState::Update(Player& player, const sf::Time delta_time) {
  player.spaceship.MoveRight(delta_time);
}
}  // namespace Game
