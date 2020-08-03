#include "Engine.h"

#include "Assets.h"

namespace Game {
Engine::Engine() {
  Assets::Instance().Load();
}

bool Engine::PollEvent(sf::Event& event) {
  return m_window.pollEvent(event);
}

void Engine::HandleInput(const sf::Event& event) {
  m_player.HandleInput(event);

  if (event.type == sf::Event::Closed) {
    m_window.close();
  }
}

void Engine::Update(const sf::Time delta_time) {
  m_player.Update(delta_time);
  Notify();
}

bool Engine::IsRuning() const { 
  return m_window.isOpen(); 
}
}  // namespace Game
