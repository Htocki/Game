#include "Graphics/Label.hpp"



Label::Label (sf::Vector2f position) 
    : Widget(position)
    , font_()
    , text_()
{
    font_.loadFromFile("media/fonts/Sansation.ttf");
    text_.setFont(font_);
    text_.setPosition(position);
    text_.setCharacterSize(12);
}

void Label::draw (sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text_, states);
}

void Label::setText (std::string string) {
    text_.setString(toString(string));
}

void Label::setPosition (sf::Vector2f position) {
    position_ = position;
    text_.setPosition(position);
}
