#include "Application.h"

#include <SFML/Window/Event.hpp>

#include "Assets.h"

namespace Game {
Application::Application() 
    : m_spaceship_view { m_player.GetSpaceship() }
{
  m_window.Attach(&m_spaceship_view);
  Attach(&m_window);
  Attach(&m_player);
}

void Application::Run() {
  sf::Event event;
  while (m_window.IsOpen()) {
    m_window.PollEvent(&event);
    NotifyEventHandlers(event);
    m_window.DrawAllEntities();
  }
}
}  // namespace Game
