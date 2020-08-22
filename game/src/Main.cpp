#include <exception>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Player.h"
#include "Spaceship.h"
#include "Window.h"

const sf::Time delay { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Assets::Instance().Load();

    Game::Window window;
    Game::Player player;
    Game::Spaceship spaceship;

    window.Attach(&spaceship);

    while (window.IsOpen()) {
      sf::Event event;
      while (window.PollEvent(event)) {
        // Input
        window.HandleInput(event);
        player.HandleInput(event);
        
        // Updating
        player.Update(delay);
        spaceship.Update(player);
        
        // Output
        window.Display();
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
