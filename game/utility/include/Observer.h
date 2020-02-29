#pragma once

#include <vector>

namespace Game 
{
    class Observer
    {
    public:
        virtual void Update() = 0;
    };

    class Observable
    {
    public:
        void AddObserver(Observer* observer) {
            m_observers.push_back(observer);
        }

        void Notify() {
            for (auto observer : m_observers) {
                observer->Update();
            }
        }
    private:
        std::vector<Observer*> m_observers;
    };
}