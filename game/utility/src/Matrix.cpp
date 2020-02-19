#include "Matrix.h"

Matrix::Matrix(
    sf::Uint64 width,
    sf::Uint64 height,
    Generator<sf::Int64> generator
)
    : width(width)
    , height(height)
    , generator(generator)
{
    vector.resize(width * height);
    for (auto& element : vector)
        element = this->generator.getValue();
}

void Matrix::update() {
    // Shift matrix values down one row
    for (sf::Uint64 i{ vector.size() - 1 }; i >= width; --i)
        vector[i] = vector[i - width];

    // Generation of new values for the first row
    for (sf::Uint64 i{ 0 }; i < width; ++i)
        vector[i] = generator.getValue();
}

void Matrix::print() {
    for (sf::Uint64 i{ 0 }; i < vector.size(); ++i) {
        if (i % width == 0)
            std::cout << std::endl;
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

sf::Int64 Matrix::getValue(sf::Uint64 i, sf::Uint64 j) const {
    return vector.at(i + j * width);
}