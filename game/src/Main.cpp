#include <iostream>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

#include "Engine.h"
#include "Controller.h"
#include "Render.h"

const sf::Time delay { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Engine engine;
    Game::Render view { &engine };
    Game::Controller controller { &engine };

    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;

    while (engine.IsRuning()) {
      sf::Time elapsed_time = clock.restart();
      time_since_last_update += elapsed_time;
      controller.HandleInput();
      while (time_since_last_update > delay) {
        time_since_last_update -= delay;
        engine.Update(delay);
      }
    }
  } catch (Game::Assets::LoadingFail) {
    std::cerr << "Resource loading failed..." << std::endl;
  } catch (...) {
    std::cerr << "Unknown error..." << std::endl;
  }
}
