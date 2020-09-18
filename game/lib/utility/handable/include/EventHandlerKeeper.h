#pragma once

#include <vector>

#include <SFML/Window/Event.hpp>

#include "EventHandler.h"

namespace Game {
class sf::Event;
class EventHandlerKeeper {
 public:
  virtual void Attach(EventHandler* event_handler);
  virtual void Detach(EventHandler* event_handler);
  virtual void NotifyEventHandlers(const sf::Event& event);

 protected:
  EventHandlerKeeper() {}

 private:
  std::vector<EventHandler*> m_event_handlers;
};
}  // namespace Game
