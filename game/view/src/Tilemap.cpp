#include "Tilemap.h"

bool Tilemap::load(
    const std::string& tileset,
    sf::Vector2u tileSize,
    Matrix tiles,
    sf::Uint64 width,
    sf::Uint64 height
){
    // Load the tileset texture
    if (!this->tileset.loadFromFile(tileset))
        return false;

    // Resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // Populate the vertex array, with one quad per tile
    for (sf::Uint64 i{ 0 }; i < width; ++i)
        for (sf::Uint64 j{ 0 }; j < height; ++j)
        {
            // Get the current tile number
            sf::Int64 tileNumber = tiles.getValue(i, j);

            // Find its position in the tileset texture
            sf::Int64 tu = tileNumber % (this->tileset.getSize().x / tileSize.x);
            sf::Int64 tv = tileNumber / (this->tileset.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // Define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // Define its t texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform
    states.transform *= getTransform();
    // Apply the tileset texture
    states.texture = &this->tileset;
    // Draw the vertex array
    target.draw(vertices, states);
}