#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Engine.h"
#include "Map.h"
#include "Observer.h"
#include "PRender.h"

namespace Game {
class Render : public Observer {
 public:
  explicit Render(Engine* engine);
  void Update() final;

 private:
  Engine* m_engine;

  sf::RenderWindow& m_window;
  Map m_map;
  PRender m_player;
};
}  // namespace Game
