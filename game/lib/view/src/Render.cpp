#include "Render.h"

Game::Render::Render(Engine* engine)
    : m_engine(engine),
      m_window(engine->WindowRef()) {
  m_engine->Attach(this);
  m_window.create(sf::VideoMode(600, 600), "Name");
  m_window.setFramerateLimit(60);
}

void Game::Render::Update() {
  m_window.clear();
  m_player_render.Render(m_engine->GetPlayer(), m_window);
  m_window.display();
}
