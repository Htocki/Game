#pragma once

#incude <SFML/System/Time.hpp>
#incude <SFML/Window/Event.hpp>



class GameObject
    : public sf::Drawable
    , public sf::NonCopyable
{
public:
    GameObject (sf::Vector2f&);
    virtual ~GameObject();

    virtual void input (sf::Event&) = 0;
    virtual void update (sf::Time&) = 0;

    void            setPosition (sf::Vector2f&);
    sf::Vector2f&   getPosition () const; 


private:
    sf::Vector2f position_;
};