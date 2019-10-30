#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <string>

#include "Utility/ToString.hpp"



class Label
        : sf::Drawable
        , sf::NonCopyable
{
public:
    Label(sf::Vector2f);
    Label(sf::Vector2f, std::string);
    void setText(std::string);
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const final;

private:
    sf::Font font_;
    sf::Text text_;
};
