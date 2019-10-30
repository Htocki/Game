#include "Statistic.hpp"



Statistic::Statistic()
    : framesPerSecod_({5.f, 5.f})
    , timeOfframe_({5.f, 18.f})
{}

void Statistic::update(sf::Time elapsedTime)
{
    updateTime_ += elapsedTime;
    numFrames_ += 1;

    if (updateTime_ >= sf::seconds(1.0f))
    {
        sf::Int64 timeOfframe = updateTime_.asMicroseconds() / numFrames_;

        framesPerSecod_.setText("frames per second:   " + toString(numFrames_));
        timeOfframe_.setText("time of frame:   " + toString(timeOfframe));

        updateTime_ -= sf::seconds(1.0f);
        numFrames_ = 0;
    }
}

void Statistic::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    framesPerSecod_.draw(target, states);
    timeOfframe_.draw(target, states);
}
