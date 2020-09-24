#pragma once

#include "Positionable.h"

namespace Game::Model {
class Spaceship : public Positionable {
 public:
  Spaceship();

  void SetSpeed(float speed);
  float GetSpeed() const;

  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();

 private:
  float m_speed;
};
}  // namespace Game::Model
