#include "Score.hpp"



Score::Score()
    : clock_()
{}


sf::Int64 Score::getScore()
{
    return static_cast<sf::Int64>(clock_.getElapsedTime().asSeconds());
}
