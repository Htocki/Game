#include "Tilemap.h"

bool Tilemap::load(
    const std::string& tileset,
    sf::Vector2u		tileSize,
    RandomizedMatrix	tiles,
    unsigned int		width,
    unsigned int		height
)
{
    // Load the tileset texture
    if (!tileset_.loadFromFile(tileset))
        return false;

    // Resize the vertex array to fit the level size
    vertices_.setPrimitiveType(sf::Quads);
    vertices_.resize(width * height * 4);

    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // Get the current tile number
            int tileNumber = tiles.getValue(i, j);

            // Find its position in the tileset texture
            int tu = tileNumber % (tileset_.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset_.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices_[(i + j * width) * 4];

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
    states.texture = &tileset_;
    // Draw the vertex array
    target.draw(vertices_, states);
}