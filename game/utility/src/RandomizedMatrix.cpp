#include "RandomizedMatrix.h"

RandomizedMatrix::RandomizedMatrix (
        unsigned int width,
        unsigned int height,
        Generator<int> generator
    )
    : width_(width)
    , height_(height)
    , generator_(generator)
{
    v.resize(width_ * height_);
    for (auto& e : v)
        e = generator_.getValue();
}

void RandomizedMatrix::update() {
    // Shift matrix values down one row
    for (auto i{v.size() - 1}; i >= width_; --i)
        v[i] = v[i-width_];

    // Generation of new values for the first row
    for (auto i{0u}; i < width_; ++i)
        v[i] = generator_.getValue();
}

void RandomizedMatrix::print() {
    for (auto i{0u}; i<v.size(); ++i) {
        if (i % width_ == 0)
            std::cout << std::endl;
        std::cout << v[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int RandomizedMatrix::getValue (unsigned int i, unsigned int j) const {
    return v.at(i + j * width_);
}
