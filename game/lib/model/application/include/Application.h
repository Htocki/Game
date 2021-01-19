#pragma once

#include "Button.h"
#include "Player.h"
#include "Text.h"
#include "VSpaceship.h"
#include "Window.h"

namespace Game {
class Application {
 public:
  Application();
  void Run();

 private:
  void HandleEvent(const sf::Event& event);
  void Draw();

  Window m_window;
  Player m_player;
  Text m_text_title;
  Button m_button_play;
  Button m_button_records;
  Button m_button_settings;
  Button m_button_exit;
  View::Spaceship m_spaceship_view;
};
}  // namespace Game
