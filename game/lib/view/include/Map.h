#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

namespace Game {
class Map {
 public:
  Map(sf::Vector2f position, sf::Vector2f size, float cell_size);
  void Draw(sf::RenderWindow* window);

 private:
  sf::Vector2f m_position { 0.f, 0.f };
  sf::Vector2f m_size { 0.f, 0.f };
  float m_cell_size { 0.f };
  std::vector<sf::Vector2f> m_node_positions;
};
}  // namespace Game
