#include "Engine.h"

Game::Engine::Engine()
    : m_state(State::Run) {
  Assets::Instance().Load();
}

Game::Player& Game::Engine::PlayerRef() { return m_player; }

bool Game::Engine::PollEvent(sf::Event& event) {
  return m_window.pollEvent(event);
}

void Game::Engine::Update(sf::Time deltaTime) {
  m_player.Update(deltaTime);
  Notify();
}

void Game::Engine::Stop() { m_window.close(); }

bool Game::Engine::IsRuning() const { return m_window.isOpen(); }
