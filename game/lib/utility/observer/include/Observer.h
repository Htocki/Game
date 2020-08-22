#pragma once

namespace Game {
class Window;

class Observer {
 public:
  virtual void Draw(Window& window) = 0;

 protected:
  Observer() {}
};
}  // namespace Game
