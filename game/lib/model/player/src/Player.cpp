#include "Player.h"

#include <memory>

#include "StandingPlayerState.h"

namespace Game {
Player::Player()
    : m_name { "Unnamed" }
    , m_state { std::make_unique<StandingPlayerState> () }
{
  spaceship.SetPosition(100.f, 100.f);
  spaceship.SetSpeed(300.f);
}

void Player::SetName(std::string name) {
  m_name = name;
}

std::string Player::GetName() const {
  return m_name;
}

void Player::HandleInput(const sf::Event& event) {
  m_state = std::move(m_state->HandleInput(*this, event));
}

void Player::Update(const sf::Time delta_time) {
  m_state->Update(*this, delta_time);
}
}  // namespace Game
