#pragma once

namespace Game {
class Observer {
 public:
  virtual void Update() = 0;

 protected:
  ~Observer() = default;
};
}  // namespace Game
