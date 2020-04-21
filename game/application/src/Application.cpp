#include "Application.h"

#include <SFML/System/Clock.hpp>

Game::Application::Application()
    : m_view{&m_engine},
      m_controller{&m_engine},
      m_delay{sf::seconds(1.f / 60.f)} {}

void Game::Application::Run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (m_engine.IsRuning()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    m_controller.HandleInput();

    while (timeSinceLastUpdate > m_delay) {
      timeSinceLastUpdate -= m_delay;
      m_engine.Update(m_delay);
    }
  }
}
