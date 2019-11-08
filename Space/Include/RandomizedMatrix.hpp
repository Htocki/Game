#pragma once

#include <vector>
#include <iostream>

#include "Utility\Generator.hpp"



class RandomizedMatrix
{
public:
    RandomizedMatrix (
        unsigned int width,
        unsigned int height,
        Generator<int> generator
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
    Generator<int> generator_;
};