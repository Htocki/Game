#pragma once

#include "Position.h"

namespace Game {
class Positioned {
 public:
  Positioned();
  explicit Positioned(Position position);
  Positioned(float x, float y);
  
  void SetPosition(Position position);
  void SetPosition(float x, float y);
  void SetPositionX(float x);
  void SetPositionY(float y);

  Position GetPosition() const;
  float GetPositionX() const;
  float GetPositionY() const;

 protected:
  Position m_position;
};
}  // namespace Game
