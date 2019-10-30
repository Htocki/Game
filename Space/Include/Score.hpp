#pragma once

#include <SFML/System/Clock.hpp>



class Score
{
public:
    Score();
    sf::Int64 getScore();

private:
    sf::Clock clock_;
};
