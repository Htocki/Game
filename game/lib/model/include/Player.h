#pragma once

#include <string>

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include "Assets.h"

namespace Game {
class Player {
 public:
  enum class State {
    Standing,
    Moving_Up,
    Moving_Down,
    Moving_Left,
    Moving_Right
  };

  Player() = default;

  std::string GetName() const { return m_name; }
  sf::Vector2f GetPosition() const { return m_position; }
  State GetState() const { return m_state; }

  void SetName(std::string name) { m_name = name; }
  void SetPosition(sf::Vector2f position) { m_position = position; }
  void SetState(State state) { m_state = state; }

  void Update(sf::Time delta_time);

 private:
  std::string m_name { "Unnamed" };
  sf::Vector2f m_position { 100.f, 100.f };
  float m_speed { 300.f };
  State m_state { State::Standing };
};
}  // namespace Game
