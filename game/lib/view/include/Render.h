#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Engine.h"
#include "Map.h"
#include "Observer.h"
#include "Spaceship.h"

namespace Game {
class Render : public Observer {
 public:
  explicit Render(Engine* engine);
  ~Render();
  void Update() final;

 private:
  Engine* m_engine;
  Map m_map;
  Spaceship m_spaceship;
};
}  // namespace Game
