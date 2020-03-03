#include "Observable.h"

void Game::Observable::AddObserver(Observer* observer) {
    m_observers.push_back(observer);
}

void Game::Observable::Notify() {
    for (auto observer : m_observers) {
        observer->OnNotify();
    }
}