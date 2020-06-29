#pragma once

#include <string>
#include <utility>

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "PlayerState.h"

namespace Game {
class Player {
 public:
  Player();
  Player(sf::Vector2f position, std::string name, float speed);

  std::string GetName() const { return m_name; }
  sf::Vector2f GetPosition() const { return m_position; }
  float GetSpeed() const { return m_speed; }

  void HandleInput(const sf::Event& event);
  void Update(const sf::Time delta_time);

  void MoveLeft(float distance) { m_position.x -= distance; };
  void MoveRight(float distance) { m_position.x += distance; };
  void SetState(std::unique_ptr<PlayerState> state) { m_state = std::move(state); };

 private:
  std::string m_name;
  sf::Vector2f m_position;
  float m_speed;
  std::unique_ptr<PlayerState> m_state;
};
}  // namespace Game
