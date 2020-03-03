#pragma once

namespace Game
{
    class Observer
    {
    public:
        virtual ~Observer() {}
        virtual void OnNotify() = 0;
    };
}

