#pragma once

namespace Game {
class Observer {
 public:
  virtual void Update() = 0;

 protected:
  Observer() {}
};
}  // namespace Game
