#pragma once

#include <vector>

#include "Observer.h"

namespace Game
{
    class Observable
    {
    public:
        void AddObserver(Observer* observer);
        void Notify();

    private:
        std::vector<Observer*> m_observers;
    };
}