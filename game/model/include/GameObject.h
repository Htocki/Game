#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>



class GameObject
    : public sf::Drawable
    , public sf::NonCopyable
{
public:
    GameObject (sf::Vector2f);
    virtual ~GameObject();

    void            setPosition (sf::Vector2f);
    sf::Vector2f    getPosition () const;


protected:
    sf::Vector2f position_;
};
