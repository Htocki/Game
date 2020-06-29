#include "Controller.h"

#include <SFML/Window/Event.hpp>

namespace Game {
void Controller::HandleInput(Engine& engine) {
  sf::Event event;
  while (engine.PollEvent(event)) {
    engine.HandleInput(event);
  }
}
}  // namespace Game

