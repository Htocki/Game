#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class Object
    : public sf::Drawable
    , private sf::NonCopyable
{
public:
    explicit Object(sf::Vector2f);
    virtual ~Object() = default;

    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition() const;

protected:
    sf::Vector2f position;
};