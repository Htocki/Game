#pragma once

namespace Game {
class Window;

class Drawable {
 public:
  virtual void Draw(Window* window) = 0;

 protected:
  Drawable() {}
};
}  // namespace Game
