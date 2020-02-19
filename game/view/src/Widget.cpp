#include "Widget.h"

Widget::Widget(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f Widget::getPosition() const {
    return position;
}