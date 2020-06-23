#include "Map.h"

namespace Game {
  Map::Map(sf::Vector2f position, sf::Vector2f size, float cell_size)
    : m_position { position }
    , m_size { size }
    , m_cell_size { cell_size }
  {
    for (float x { m_position.x }; x <= m_size.x; x += m_cell_size) {
      for (float y { m_position.y }; y <= m_size.y; y += m_cell_size) {
        m_node_positions.push_back(sf::Vector2f{ x, y });
      }
    }
  }

  void Map::Draw(sf::RenderWindow* window) {
    // Фон игрового поля
    sf::RectangleShape rectangle { sf::Vector2f{ m_size } };
    rectangle.setPosition(m_position);
    rectangle.setFillColor(sf::Color::Green);
    window->draw(rectangle);

    // Сетка
    for (const auto& node_position : m_node_positions) {
      sf::RectangleShape cell { sf::Vector2f{ m_cell_size, m_cell_size } };
      cell.setPosition(node_position);
      cell.setFillColor(sf::Color::Red);
      cell.setOutlineThickness(1.f);
      cell.setOutlineColor(sf::Color::White);
      window->draw(cell);
    }

    // Узлы
    for (const auto& node_position : m_node_positions) {
      sf::CircleShape circle(3);
      circle.setFillColor(sf::Color::Blue);
      circle.setPosition(node_position);
      circle.setOrigin(2, 2);
      window->draw(circle);
    }
  }
}  // namespace Game
