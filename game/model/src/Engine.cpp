#include "Engine.h"

Game::Engine::Engine()
    : m_state(State::Run)
{
    Assets::Instance().Load();
}

auto Game::Engine::PlayerRef() -> Game::Player& {
    return m_player;
}

bool Game::Engine::PollEvent(sf::Event& event) {
    return m_window.pollEvent(event);
}

void Game::Engine::Update(sf::Time deltaTime) {
    Notify();
    m_player.Update(deltaTime);
}

void Game::Engine::Stop() {
    m_window.close();
}

bool Game::Engine::IsRuning() const {
    return m_window.isOpen();
}