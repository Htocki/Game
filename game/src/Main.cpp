#include <exception>
#include <iostream>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Controller.h"
#include "Engine.h"
#include "Render.h"

const sf::Time delay { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Assets::Instance().Load();

    Game::Engine engine;
    Game::Render view { &engine };
    Game::Controller controller { &engine };

    while (engine.window.isOpen()) {
    sf::Event event;
      while (engine.window.pollEvent(event)) {
        controller.HandleInput(event);
        engine.Update(delay);
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
