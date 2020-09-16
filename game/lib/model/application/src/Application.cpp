#include "Application.h"

#include <SFML/Window/Event.hpp>

#include "Assets.h"

namespace Game {
Application::Application() 
    : m_spaceship_view { m_player.GetSpaceship() }
{
  m_window.Attach(&m_spaceship_view);
}

void Application::Run() {
  while (m_window.IsOpen()) {
    const sf::Time delta_time { sf::seconds(1.f / 60.f) };
    sf::Event event;
    while (m_window.PollEvent(&event)) {
      m_window.HandleEvent(event);
      m_player.HandleEvent(event, delta_time);
      m_window.DrawAllEntities();
    }
  }
}
}  // namespace Game
