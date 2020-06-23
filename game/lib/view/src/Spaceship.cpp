#include "Spaceship.h"

Game::Spaceship::Spaceship(Player* player)
    : m_player { player } {
  m_spaceship.setTexture(Assets::Instance().spaceship);
}

void Game::Spaceship::Draw(sf::RenderWindow* window) {
  m_spaceship.setPosition(m_player->GetPosition());
  window->draw(m_spaceship);
}
