#pragma once

namespace Game {
class Subject;
}  // namespace Game

namespace Game {
class Observer {
 public:
  virtual void Update() = 0;

 protected:
  Observer() {}
};
}  // namespace Game
