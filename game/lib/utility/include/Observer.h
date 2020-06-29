#pragma once

namespace Game {
class Observer {
 public:
  virtual void Draw() = 0;

 protected:
  Observer() {}
};
}  // namespace Game
