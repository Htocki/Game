#include "Matrix.h"

Matrix::Matrix(
    sf::Uint64 width,
    sf::Uint64 height,
    Generator<sf::Int64> generator
)
    : width_(width)
    , height_(height)
    , generator_(generator)
{
    vector_.resize(width_ * height_);
    for (auto& element : vector_)
        element = generator_.getValue();
}

void Matrix::update() {
    // Shift matrix values down one row
    for (sf::Uint64 i{ vector_.size() - 1 }; i >= width_; --i)
        vector_[i] = vector_[i - width_];

    // Generation of new values for the first row
    for (sf::Uint64 i{ 0 }; i < width_; ++i)
        vector_[i] = generator_.getValue();
}

void Matrix::print() {
    for (sf::Uint64 i{ 0 }; i < vector_.size(); ++i) {
        if (i % width_ == 0)
            std::cout << std::endl;
        std::cout << vector_[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

sf::Int64 Matrix::getValue(sf::Uint64 i, sf::Uint64 j) const {
    return vector_.at(i + j * width_);
}