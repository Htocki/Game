#pragma once

namespace Game {
class sf::Event;
class EventHandler {
 public:
  virtual void HandleEvent(const sf::Event& event) = 0;

 protected:
  EventHandler() {}
};
}  // namespace Game