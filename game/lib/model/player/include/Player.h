#pragma once

#include <string>
#include <utility>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "PlayerState.h"
#include "MSpaceship.h"

namespace Game {
class Player {
 public:
  Player();

  void SetName(std::string name);
  std::string GetName() const;

  void HandleInput(const sf::Event& event);
  void Update(const sf::Time delta_time);
  
  Model::Spaceship spaceship;

 private:
  std::string m_name;
  std::unique_ptr<PlayerState> m_state;
};
}  // namespace Game
