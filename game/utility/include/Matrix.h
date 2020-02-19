#pragma once

#include <iostream>
#include <vector>

#include <SFML/System.hpp>

#include "Generator.h"

class Matrix
{
public:
    Matrix(
        sf::Uint64 width,
        sf::Uint64 height,
        Generator<sf::Int64> generator
    );

    void update();
    void print();

    sf::Int64 getValue(
        sf::Uint64 i,
        sf::Uint64 j
    ) const;

private:
    std::vector<sf::Int64> vector;
    sf::Uint64 width;
    sf::Uint64 height;
    Generator<sf::Int64> generator;
};
