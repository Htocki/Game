#include "Controller.h"

#include <SFML/Window/Event.hpp>

Game::Controller::Controller(Engine& engine)
  : m_engine { engine }
  , m_player { engine.player }
{}

void Game::Controller::HandleInput() {
  while (m_engine.window.isOpen()) {
    sf::Event event;
    while (m_engine.window.pollEvent(event)) {
      m_player.HandleInput(event);

      switch (event.type) {
      case sf::Event::Closed:
        m_engine.window.close();
        break;

      default:
        break;
      }
    }
  }
}
