#pragma once

#include <SFML/Graphics/RectangleShape.hpp>



class Area
{
public:
    Area();

    sf::Vector2f getLeft();
    sf::Vector2f getRight();
    sf::Vector2f getTop();
    sf::Vector2f getDown();

    bool isIn();

private:
    sf::RectangleShape area_;
};
