#include <exception>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Player.h"
#include "VSpaceship.h"
#include "Window.h"

static const sf::Time delta_time { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Assets::Instance().Load();
    
    // Initialize.
    Game::Window window;
    Game::Player player;
    Game::View::Spaceship spaceship_view { player.spaceship };

    // Linking view and window entities.
    window.Attach(&spaceship_view);

    while (window.IsOpen()) {
      sf::Event event;
      while (window.PollEvent(event)) {
        window.HandleInput(event);
        player.HandleInput(event, delta_time);        
        window.Display();
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
