#pragma once

#include <SFML/System/Time.hpp>

#include "Controller.h"
#include "Engine.h"
#include "Render.h"

namespace Game {
class Application {
 public:
  Application();
  void Run();

 private:
  Engine m_engine;
  Render m_view;
  Controller m_controller;

  const sf::Time m_delay;
};
}  // namespace Game
