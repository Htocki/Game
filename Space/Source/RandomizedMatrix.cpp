#include "RandomizedMatrix.hpp"

RandomizedMatrix::RandomizedMatrix (
        unsigned int width,
        unsigned int height,
        ValueGenerator<int> generator
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
    // Смещение значений матрицы на один ряд вниз
    for (auto i{v.size() - 1}; i >= width_; --i)
        v[i] = v[i-width_];

    // Генерация новых значений для первого ряда
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
