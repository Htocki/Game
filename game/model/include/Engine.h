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
  enum class State {
    GameOver,
    Loading,
    Menu,
    Pause,
    Records,
    Run,
    Settings
  };

  Engine();

  State GetState() const { return m_state; }
  Player GetPlayer() const { return m_player; }

  void SetState(State state) { m_state = state; }

  Player& PlayerRef();
  sf::RenderWindow& WindowRef() { return m_window; }

  bool PollEvent(sf::Event& event);
  void Update(sf::Time deltaTime);
  void Stop();

  bool IsRuning() const;

 private:
  Player m_player;
  State m_state;
  sf::RenderWindow m_window;
};
}  // namespace Game
