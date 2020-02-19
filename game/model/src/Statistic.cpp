#include "Statistic.h"

void Statistic::update(sf::Time elapsedTime) {
    updateTime += elapsedTime;
    numFrames += 1;

    if (updateTime >= sf::seconds(1.0f))
    {
        timeOfFrame = updateTime.asMicroseconds() / numFrames;
        framesPerSecond = numFrames;
        updateTime -= sf::seconds(1.0f);
        numFrames = 0;
    }
}

sf::Int64 Statistic::getFramesPerSecond() const {
    return framesPerSecond;
}

sf::Int64 Statistic::getTimeOfFrame() const {
    return timeOfFrame;
}