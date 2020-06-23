#include "Render.h"

#include <iostream>

Game::Render::Render(Engine* engine)
  : m_engine { engine }
  , m_map { sf::Vector2f{ 20, 20 }, sf::Vector2f{ 500, 410 }, 30 }
  , m_spaceship { &engine->player }
{
  m_engine->Attach(this);
  m_engine->window.create(sf::VideoMode(600, 600), "Points");
  m_map.Draw(&m_engine->window);
}

void Game::Render::Update() {
  m_engine->window.clear();
  m_map.Draw(&m_engine->window);
  m_spaceship.Draw(&m_engine->window);
  m_engine->window.display();
}

Game::Render::~Render() {
  m_engine->Detach(this);
}
