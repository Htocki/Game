#pragma once

#include <SFML/System/Time.hpp>

#include "Positionable.h"

namespace Game::Model {
class Spaceship : public Positionable {
 public:
  Spaceship();

  void SetSpeed(float speed);
  float GetSpeed() const;

  void MoveLeft(const sf::Time delta_time);
  void MoveRight(const sf::Time delta_time);
  void MoveUp(const sf::Time delta_time);
  void MoveDown(const sf::Time delta_time);

 private:
  float m_speed;
};
}  // namespace Game::Model
