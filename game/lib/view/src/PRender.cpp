#include "PRender.h"

Game::PRender::PRender() {
  m_spaceship.setTexture(Assets::Instance().spaceship);
}

void Game::PRender::Render(
    const Player& player,
    sf::RenderWindow& window) {
  Update(player);
  window.draw(m_spaceship);
}

void Game::PRender::Update(const Player& player) {
  m_spaceship.setPosition(player.GetPosition());
}

void Game::PRender::draw(
    sf::RenderTarget& target,
    sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(m_spaceship, states);
}
