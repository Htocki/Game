#pragma once

#include <SFML/System/Vector2.hpp>

namespace Game {
class Positionable {
 public:
  Positionable();
  explicit Positionable(sf::Vector2f position);
  Positionable(float x, float y);
  
  void SetPosition(sf::Vector2f position);
  void SetPosition(float x, float y);
  void SetPositionX(float x);
  void SetPositionY(float y);

  sf::Vector2f GetPosition() const;
  float GetPositionX() const;
  float GetPositionY() const;

 private:
  sf::Vector2f m_position;
};
}  // namespace Game
