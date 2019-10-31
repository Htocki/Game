#include "Graphics/Area.hpp"



Area::Area() {}

sf::Vector2f Area::getLeft()  { return {0.f, 0.f}; }
sf::Vector2f Area::getRight() { return {0.f, 0.f}; }
sf::Vector2f Area::getTop()   { return {0.f, 0.f}; }
sf::Vector2f Area::getDown()  { return {0.f, 0.f}; }

bool Area::isIn() { return true; }
