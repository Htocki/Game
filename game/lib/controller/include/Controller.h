#pragma once

#include "PController.h"
#include "Engine.h"

namespace Game {
class Controller {
 public:
  explicit Controller(Engine* engine);
  void HandleInput();

 private:
  Engine* m_engine;
  PController m_player;
};
}  // namespace Game
