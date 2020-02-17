#include "Widget.h"

Widget::Widget(sf::Vector2f position) {
    position_ = position;
}

Widget::~Widget() {}

sf::Vector2f Widget::getPosition() const {
    return position_;
}