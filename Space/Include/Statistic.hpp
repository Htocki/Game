#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include "Graphics/Label.hpp"



class Statistic
        : private sf::NonCopyable
{
public:
    Statistic();
    void update(sf::Time);
    void draw(sf::RenderTarget&, sf::RenderStates) const;

private:
    Label framesPerSecod_;
    Label timeOfframe_;
    sf::Time updateTime_;
    sf::Int64 numFrames_;
};
