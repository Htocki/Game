#pragma once

#include <string>
#include <utility>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "PlayerState.h"
#include "Position.h"
#include "Positionable.h"

namespace Game {
class Player : public Positionable {
 public:
  Player();
  Player(Position position, std::string name, float speed);

  void SetName(std::string name);
  void SetSpeed(float speed);

  std::string GetName() const;
  float GetSpeed() const;

  void HandleInput(const sf::Event& event);
  void Update(const sf::Time delta_time);

  void MoveLeft(float distance);
  void MoveRight(float distance);

 private:
  std::string m_name;
  float m_speed;
  std::unique_ptr<PlayerState> m_state;
};
}  // namespace Game
