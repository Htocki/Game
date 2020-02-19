#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "Matrix.h"

class Tilemap 
	: public sf::Drawable
	, public sf::Transformable
{
public:
	bool load(
		const std::string& tileset,
		sf::Vector2u tileSize,
		Matrix tiles,
		sf::Uint64 width,
		sf::Uint64 height
	);

private:
	virtual void draw(
		sf::RenderTarget& target,
		sf::RenderStates states
	) const;

	sf::VertexArray vertices;
	sf::Texture tileset;
};
