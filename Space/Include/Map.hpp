#pragma once

#include <string>



class Map 
    : public sf::Drawable
    , public sf::Transformable
{
public:
    bool load (
        const std::string&  tileset,
        sf::Vector2u        tileSize,
        const int*          tiles,
        unsigned int        width,
        unsigned int        height
    );


private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    sf::VertexArray vertices_;
    sf::Texture     teleset_;
}

// map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8)