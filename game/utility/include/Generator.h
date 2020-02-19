#pragma once

#include <random>

template <typename T>
class Generator
{
public:
    Generator(T min, T max)
        : min(min)
        , max(max)
    {}

    T getValue() {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(generator);
    }

    void setRange(T min, T max) {
        this->min = min;
        this->max = max;
    }

private:
    T min, max;
};