#include "Controller.h"

Game::Controller::Controller(Engine* engine)
  : m_engine { engine }
  , m_player { engine->player }
{}

void Game::Controller::HandleInput(const sf::Event& event) {
  m_player.HandleInput(event);

  switch (event.type) {
  case sf::Event::Closed:
    m_engine->window.close();
    break;

  default:
    break;
  }
}
