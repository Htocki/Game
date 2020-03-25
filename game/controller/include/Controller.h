#pragma once

#include "InputPlayer.h"
#include "Engine.h"

namespace Game {
class Controller {
 public:
    explicit Controller(Engine* engine);
    void HandleInput();

 private:
    Engine* m_engine;
    InputPlayer m_player;
};
}  // namespace Game
