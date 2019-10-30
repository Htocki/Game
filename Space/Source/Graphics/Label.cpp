#include "Graphics/Label.hpp"



Label::Label(sf::Vector2f position)
    : font_()
    , text_()
{
    font_.loadFromFile("Media/Fonts/Sansation.ttf");
    text_.setFont(font_);
    text_.setPosition(position);
    text_.setCharacterSize(12);
}

Label::Label(sf::Vector2f position, std::string string)
    : Label(position)
{
    text_.setString(toString(string));
}


void Label::setText(std::string string)
{
    text_.setString(toString(string));
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(text_, states);
}
