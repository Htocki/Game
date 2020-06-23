#include "PController.h"

#include <SFML/Window/Keyboard.hpp>

void Game::PController::HandleInput(Player& player, sf::Event& event) {
  switch (player.GetState()) {
    case Player::State::Standing:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            player.SetState(Player::State::MovingLeft);
            break;

          case sf::Keyboard::Right:
            player.SetState(Player::State::MovingRight);
            break;

          default:
            break;
        }
      }
      break;

    case Player::State::MovingLeft:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Right:
            player.SetState(Player::State::MovingRight);
            break;

          default:
            break;
        }
      } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            player.SetState(Player::State::Standing);
            break;

          default:
            break;
        }
      }
      break;

    case Player::State::MovingRight:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            player.SetState(Player::State::MovingLeft);
            break;

          default:
            break;
        }
      } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
          case sf::Keyboard::Right:
            player.SetState(Player::State::Standing);
            break;

          default:
            break;
        }
      }
      break;

    default:
      break;
  }
}
