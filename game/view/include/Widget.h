#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/NonCopyable.hpp>

class Widget
    : public sf::Drawable
    , public sf::NonCopyable
{
public:
    Widget(sf::Vector2f);
    virtual ~Widget();

    virtual void setPosition(sf::Vector2f) = 0;
    sf::Vector2f getPosition() const;

protected:
    sf::Vector2f position_;
};