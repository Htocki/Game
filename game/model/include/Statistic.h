#pragma once

#include <SFML/System/Time.hpp>

#include "Label.h"

class Statistic
{
public:
    virtual void update(sf::Time);

    sf::Int64 getFramesPerSecond() const;
    sf::Int64 getTimeOfFrame() const;
  
private:
    sf::Time updateTime;
    sf::Int64 numFrames;

    sf::Int64 framesPerSecond;
    sf::Int64 timeOfFrame;
};
