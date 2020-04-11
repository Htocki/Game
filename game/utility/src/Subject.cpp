#include "Subject.h"

namespace Game {
  void Subject::Attach(Observer* observer) {
    m_observers.push_back(observer);
  }

  void Subject::Detach(Observer* observer) {
    // Найти указанного наблюдателя и удалить из вектора
  }

  void Subject::Notify() {
    for (auto& observer : m_observers) {
      observer->Update();
    }
  }
}  // namespace Game
