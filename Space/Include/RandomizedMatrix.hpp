#pragma once

#include <vector>
#include <iostream>

#include "Utility\ValueGenerator.hpp"



class RandomizedMatrix
{
public:
    RandomizedMatrix (
        unsigned int width,
        unsigned int height,
        ValueGenerator<int> generator
    );

    void update();
    void print();

    int getValue (
        unsigned int i,
        unsigned int j
    ) const;


private:
    std::vector<int> v;
    unsigned int width_;
    unsigned int height_;
    ValueGenerator<int> generator_;
};