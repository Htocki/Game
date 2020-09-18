#include "EventHandlerKeeper.h"

#include <algorithm>

#include <SFML/Window/Event.hpp>

namespace Game {
void EventHandlerKeeper::Attach(EventHandler* event_handler) {
  m_event_handlers.push_back(event_handler);
}

void EventHandlerKeeper::Detach(EventHandler* event_handler) {
  auto new_end = std::remove(
    std::begin(m_event_handlers),
    std::end(m_event_handlers),
    event_handler);
  m_event_handlers.erase(new_end, m_event_handlers.end());
}

void EventHandlerKeeper::NotifyEventHandlers(const sf::Event& event) {
  for (const auto& event_handler : m_event_handlers) {
    event_handler->HandleEvent(event);
  }
}
}  // namespace Game
