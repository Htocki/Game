#pragma once

#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ToString.h"
#include "Widget.h"

class Label : public Widget
{
public:
    Label(sf::Vector2f);

    virtual void draw(
        sf::RenderTarget&, 
        sf::RenderStates
    ) const final;

    void            setText(std::string);
    virtual void    setPosition(sf::Vector2f) final;

private:
    sf::Font font_;
    sf::Text text_;
};
