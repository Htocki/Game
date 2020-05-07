#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

class Map {
 public:
  Map(sf::Vector2f position, sf::Vector2f size, float cell_size)
    : m_position { position }
    , m_size { size }
    , m_cell_size { cell_size }
  {
    node_positions.resize(3000);
  }

  void Draw(sf::RenderWindow& window) {
    // Фон игрового поля
    sf::RectangleShape rectangle { sf::Vector2f{ m_size } };
    rectangle.setPosition(m_position);
    rectangle.setFillColor(sf::Color::Red);
    window.draw(rectangle);

    // Сетка
    for (float x { m_position.x }; x <= m_size.x; x += m_cell_size) {
      sf::Vertex line[] {
        sf::Vertex(sf::Vector2f(x, m_position.y)),
        sf::Vertex(sf::Vector2f(x, m_position.y + m_size.y))
      };
      window.draw(line, 2, sf::Lines);
    }

    for (float y { m_position.y }; y <= m_size.y; y += m_cell_size) {
      sf::Vertex line[] {
        sf::Vertex(sf::Vector2f(m_position.x, y)),
        sf::Vertex(sf::Vector2f(m_position.x + m_size.x, y))
      };
      window.draw(line, 2, sf::Lines);
    }

    // Узлы

    for (float x { m_position.x }; x <= m_size.x; x += m_cell_size) {
      for (float y { m_position.y }; y <= m_size.y; y += m_cell_size) {
        node_positions.push_back(sf::Vector2f{ x, y });
      }
    }
    for (const auto& node_position : node_positions) {
      sf::CircleShape circle(5);
      circle.setFillColor(sf::Color::Blue);
      circle.setPosition(node_position);
      window.draw(circle);
    }
  }

 private:
  sf::Vector2f m_position = { 0.f, 0.f };
  sf::Vector2f m_size = { 0.f, 0.f };
  float m_cell_size { 0.f };
  std::vector<sf::Vector2f> node_positions;
};
