#pragma once

#include "EventHandlerKeeper.h"
#include "Player.h"
#include "VSpaceship.h"
#include "Window.h"

namespace Game {
class Application : public EventHandlerKeeper {
 public:
  Application();
  void Run();

 private:
  Window m_window;
  Player m_player;
  View::Spaceship m_spaceship_view;
};
}  // namespace Game
