#include "Statistic.hpp"



void Statistic::update (sf::Time elapsedTime) {
    updateTime_ += elapsedTime;
    numFrames_ += 1;

    if (updateTime_ >= sf::seconds(1.0f))
    {
        timeOfFrame_ = updateTime_.asMicroseconds() / numFrames_;

        framesPerSecond_ = numFrames_;

        updateTime_ -= sf::seconds(1.0f);
        numFrames_ = 0;
    }
}

sf::Int64 Statistic::getFramesPerSecond () const {
    return framesPerSecond_;
}

sf::Int64 Statistic::getTimeOfFrame () const {
    return timeOfFrame_;
}