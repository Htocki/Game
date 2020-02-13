#pragma once
#include <SFML/System/Time.hpp>
#include "Label.h"



class Statistic
{
public:
    virtual void    update (sf::Time);

    sf::Int64   getFramesPerSecond () const;
    sf::Int64   getTimeOfFrame () const;


private:
    sf::Time    updateTime_;
    sf::Int64   numFrames_ ;

    sf::Int64   framesPerSecond_;
    sf::Int64   timeOfFrame_;
};
