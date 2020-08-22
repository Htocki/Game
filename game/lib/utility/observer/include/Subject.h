#pragma once

#include <vector>

#include "Observer.h"

namespace Game {
class Window;
class Subject {
 public:
  virtual void Attach(Observer* observer);
  virtual void Detach(Observer* observer);
  virtual void Notify(Window& window);

 protected:
  Subject() {}

 private:
  std::vector<Observer*> m_observers;
};
}  // namespace Game
