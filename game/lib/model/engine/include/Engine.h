#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.h"
#include "Subject.h"
#include "Player.h"

namespace Game {
class Engine : public Subject {
 public:
  Engine();
  Player& GetPlayer() { return m_player; };
  sf::RenderWindow& WindowRef() { return m_window; }
  bool PollEvent(sf::Event& event);
  void HandleInput(const sf::Event& event);
  void Update(const sf::Time delta_time);
  bool IsRuning() const;

 private:
  Player m_player;
  sf::RenderWindow m_window;
};
}  // namespace Game
