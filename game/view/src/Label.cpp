#include "Label.h"

Label::Label(sf::Vector2f position)
    : Widget(position)
    , font()
    , text()
{
    font.loadFromFile("media/fonts/Sansation.ttf");
    text.setFont(font);
    text.setPosition(position);
    text.setCharacterSize(12);
}

void Label::draw(
    sf::RenderTarget& target,
    sf::RenderStates states
) const {
    target.draw(text, states);
}

void Label::setText(std::string string) {
    text.setString(toString(string));
}

void Label::setPosition(sf::Vector2f position) {
    this->position = position;
    text.setPosition(this->position);
}
