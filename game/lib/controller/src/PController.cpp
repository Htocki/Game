#include "PController.h"

#include <SFML/Window/Keyboard.hpp>

Game::PController::PController(Player& player)
  : m_player { player }
{}

void Game::PController::HandleInput(const sf::Event& event) {
  switch (m_player.GetState()) {
    case Player::State::Standing:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            m_player.SetState(Player::State::Moving_Left);
            break;

          case sf::Keyboard::Right:
            m_player.SetState(Player::State::Moving_Right);
            break;

          default:
            break;
        }
      }
      break;

    case Player::State::Moving_Left:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Right:
            m_player.SetState(Player::State::Moving_Right);
            break;

          default:
            break;
        }
      } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            m_player.SetState(Player::State::Standing);
            break;

          default:
            break;
        }
      }
      break;

    case Player::State::Moving_Right:
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
          case sf::Keyboard::Left:
            m_player.SetState(Player::State::Moving_Left);
            break;

          default:
            break;
        }
      } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
          case sf::Keyboard::Right:
            m_player.SetState(Player::State::Standing);
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
