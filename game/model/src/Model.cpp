#include "Model.h"

Game::Model::Model()
    : m_state(State::Run)
{
    Assets::Instance().Load();
}

auto Game::Model::WindowRef() -> sf::RenderWindow& {
    return m_window;
}

auto Game::Model::PlayerRef() -> Game::Player& {
    return m_player;
}

void Game::Model::Update(sf::Time deltaTime) {
    Notify();
    m_player.Update(deltaTime);
}