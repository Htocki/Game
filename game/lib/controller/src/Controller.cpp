#include "Controller.h"

#include <SFML/Window/Event.hpp>

void Game::Controller::HandleInput(Engine& engine) {
  sf::Event event;
  while (engine.PollEvent(event)) {
    engine.HandleInput(event);
  }
}
