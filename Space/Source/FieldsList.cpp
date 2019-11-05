#include "FieldsList.hpp"



FieldsList::FieldsList (
        unsigned int fieldSize,
        unsigned int listSize,
        Range range
    )
        : range_(range)
        , fieldSize_(fieldSize)
        , listSize_(listSize)
{
    list_ = generateList();
}

void FieldsList::update() {
    addField();
    removeField();
}

void FieldsList::addField () {
    list_.push_front(generateField());
}

void FieldsList::removeField () {
    list_.pop_back();
}

Number FieldsList::generateNumber () {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<Number> distribution(range_.left, range_.right);
    return distribution(generator);
}

Field FieldsList::generateField () {
    Field field;
    for (unsigned int i{0}; i < fieldSize_; ++i)
        field.push_back(generateNumber());
    return field;
}

List FieldsList::generateList() {
    List list;
    for (unsigned int i{0}; i < fieldSize_; ++i)
        list.push_back(generateField());
    return list;

}

void FieldsList::print() {
    for (const auto& fild : list_)
    {
        for (const auto number : fild)
            std::cout << number << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}
