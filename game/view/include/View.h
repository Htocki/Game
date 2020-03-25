#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Engine.h"
#include "Observer.h"
#include "RenderPlayer.h"

namespace Game {
class View : public Observer {
 public:
  explicit View(Engine* engine);
  void OnNotify() final;

 private:
  Engine* m_engine;
  RenderPlayer m_player;

  sf::RenderWindow& m_window;
};
}  // namespace Game
