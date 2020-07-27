#include <exception>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Engine.h"
#include "Render.h"

const sf::Time delay { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Engine engine;
    Game::Render view { &engine };

    while (engine.IsRuning()) {
      sf::Event event;
      while (engine.PollEvent(event)) {
        engine.HandleInput(event);
        engine.Update(delay);
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
