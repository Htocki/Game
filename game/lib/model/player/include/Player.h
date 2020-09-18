#pragma once

#include <string>

#include <SFML/Window/Event.hpp>

#include "EventHandler.h"
#include "MSpaceship.h"

namespace Game {
class Player : public EventHandler {
 public:
  Player();

  void SetName(std::string name);
  std::string GetName() const;
  const Model::Spaceship& GetSpaceship() const;

  void HandleEvent(const sf::Event& event) final;
  
 private:
  Model::Spaceship m_spaceship;
  std::string m_name;
};
}  // namespace Game
