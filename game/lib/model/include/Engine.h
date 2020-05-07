#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Subject.h"
#include "Player.h"

namespace Game {
class Engine : public Subject {
 public:
  Engine();
  void Update(sf::Time deltaTime);

  Player player;
  sf::RenderWindow window;
};
}  // namespace Game
