#include "Player.h"

#include <memory>

#include "StandingPlayerState.h"

namespace Game {
Player::Player()
  : m_name { "Unnamed" }
  , m_position { 100.f, 100.f}
  , m_speed { 300.f }
  , m_state { std::make_unique<StandingPlayerState> () }
{}

Player::Player(
    sf::Vector2f position,
    std::string name,
    float speed
)
  : m_name { name }
  , m_position { position }
  , m_speed { speed }
  , m_state { std::make_unique<StandingPlayerState> () }
{}

void Player::HandleInput(const sf::Event& event) {
  m_state->HandleInput(*this, event);
}

void Player::Update(const sf::Time delta_time) {
  m_state->Update(*this, delta_time);
}
}  // namespace Game
