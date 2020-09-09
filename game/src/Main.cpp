#include <exception>
#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Player.h"
#include "VSpaceship.h"
#include "Window.h"

const sf::Time delay { sf::seconds(1.f / 60.f) };

int main() {
  try {
    Game::Assets::Instance().Load();
    
    // Initialize.
    Game::Window window;
    Game::Player player;
    Game::View::Spaceship spaceship_view;

    // Linking the entities of the view and model.
    spaceship_view.Link(&player.spaceship);
    
    // Linking view and window entities.
    window.Attach(&spaceship_view);

    while (window.IsOpen()) {
      sf::Event event;
      while (window.PollEvent(event)) {
        window.HandleInput(event);
        player.HandleInput(event);
        
        player.Update(delay);
        
        window.Display();
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
