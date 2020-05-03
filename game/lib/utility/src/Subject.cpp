#include "Subject.h"

#include <algorithm>

namespace Game {
  void Subject::Attach(Observer* observer) {
    m_observers.push_back(observer);
  }

  void Subject::Detach(Observer* observer) {
    auto new_end = std::remove(
      std::begin(m_observers),
      std::end(m_observers),
      observer);
    m_observers.erase(new_end, m_observers.end());
  }

  void Subject::Notify() {
    for (auto& observer : m_observers) {
      observer->Update();
    }
  }
}  // namespace Game
