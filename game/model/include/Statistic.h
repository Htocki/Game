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
    sf::Time updateTime_ = { sf::Time::Zero };
    sf::Int64 numFrames_ = { 0 };
    sf::Int64 framesPerSecond_ = { 0 };
    sf::Int64 timeOfFrame_ = { 0 };
};
