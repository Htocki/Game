#include "Object.h"

Object::Object(sf::Vector2f position) {
    this->position = position;
}

void Object::setPosition(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f Object::getPosition() const {
    return position;
}