#pragma once

#include <random>

template <typename T>
class Generator
{
public:
    Generator(T min, T max)
        : min_(min)
        , max_(max)
    {}

    T getValue() {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<T> distribution(min_, max_);
        return distribution(generator);
    }

    void setRange(T min, T max) {
        min_ = min;
        max_ = max;
    }

private:
    T   min_,
        max_;
};