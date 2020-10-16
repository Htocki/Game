#pragma once

#include <SFML/Window/Event.hpp>

namespace Game {
class EventHandler {
 public:
  virtual void HandleEvent(const sf::Event& event) = 0;

 protected:
  EventHandler() {}
};
}  // namespace Game
