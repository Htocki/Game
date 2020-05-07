#pragma once

namespace Game {
class Subject;
}  // namespace Game

namespace Game {
class Observer {
 public:
  virtual ~Observer() {}
  virtual void Update();

 protected:
  Observer() {}
};
}  // namespace Game
