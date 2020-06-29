#include "Engine.h"

Game::Engine::Engine()
    : m_state(State::Run) {
  Assets::Instance().Load();
}

bool Game::Engine::PollEvent(sf::Event& event) {
  return m_window.pollEvent(event);
}

void Game::Engine::HandleInput(const sf::Event& event) {
  m_player.HandleInput(event);

  if (event.type == sf::Event::Closed) {
    m_window.close();
  }
}

void Game::Engine::Update(const sf::Time delta_time) {
  m_player.Update(delta_time);
  Notify();
}

bool Game::Engine::IsRuning() const { return m_window.isOpen(); }
