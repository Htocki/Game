#include "Object.h"

Object::Object(sf::Vector2f position) {
    position_ = position;
}

void Object::setPosition(sf::Vector2f position) {
    position_ = position;
}

sf::Vector2f Object::getPosition() const {
    return position_;
}