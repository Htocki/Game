#pragma once

#include <vector>

#include "Observer.h"

namespace Game {
class Subject {
 public:
  virtual ~Subject() {}
  virtual void Attach(Observer*);
  virtual void Detach(Observer*);
  virtual void Notify();

 protected:
  Subject() {}

 private:
  std::vector<Observer*> m_observers;
};
}  // namespace Game
