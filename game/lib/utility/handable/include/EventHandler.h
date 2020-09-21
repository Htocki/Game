#pragma once

class sf::Event;

namespace Game {
class EventHandler {
 public:
  virtual void HandleEvent(const sf::Event& event) = 0;

 protected:
  EventHandler() {}
};
}  // namespace Game