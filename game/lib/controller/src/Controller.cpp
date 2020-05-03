#include "Controller.h"

#include <SFML/Window/Event.hpp>

Game::Controller::Controller(Engine* engine)
    : m_engine(engine) {}

void Game::Controller::HandleInput() {
  sf::Event event;

  while (m_engine->PollEvent(event)) {
    switch (m_engine->GetState()) {
      case Engine::State::GameOver:
        break;

      case Engine::State::Loading:
        break;

      case Engine::State::Menu:
        break;

      case Engine::State::Pause:
        break;

      case Engine::State::Records:
        break;

      case Engine::State::Run:
        m_player.HandleInput(m_engine->PlayerRef(), event);
        break;

      case Engine::State::Settings:
        break;

      default:
        break;
    }

    switch (event.type) {
      case sf::Event::Closed:
        m_engine->Stop();
        break;

      default:
        break;
    }
  }
}
