#include "GameObject.hpp"

GameObject::GameObject (sf::Vector2f position) {
    position_ = position;
}

GameObject::~GameObject () {}

void GameObject::setPosition (sf::Vector2f position) {
    position_ = position;
}

sf::Vector2f GameObject::getPosition () const {
    return position_;
}