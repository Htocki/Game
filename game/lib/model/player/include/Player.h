#pragma once

#include <string>
#include <utility>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "MSpaceship.h"

namespace Game {
class Player {
 public:
  Player();

  void SetName(std::string name);
  std::string GetName() const;
  const Model::Spaceship& GetSpaceship() const;

  void HandleEvent(const sf::Event& event, const sf::Time delta_time);
  
 private:
  Model::Spaceship m_spaceship;
  std::string m_name;
};
}  // namespace Game
