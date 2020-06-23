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
  Engine() = default;
  void Update(sf::Time delta_time);

  Player player;
  sf::RenderWindow window;
};
}  // namespace Game
