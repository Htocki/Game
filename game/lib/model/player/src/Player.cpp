#include "Player.h"

#include <memory>

#include "StandingPlayerState.h"

namespace Game {
Player::Player()
    : m_name { "Unnamed" }
    , m_speed { 300.f }
    , m_state { std::make_unique<StandingPlayerState> () }
{
  SetPosition(100.f, 100.f);
}

Player::Player(
  Position position,
  std::string name,
  float speed
)
    : m_name { name }
    , m_speed { speed }
    , m_state { std::make_unique<StandingPlayerState> () }
{
  SetPosition(position);
}

void Player::SetName(std::string name) {
  m_name = name;
}

void Player::SetSpeed(float speed) {
  m_speed = speed;
}

std::string Player::GetName() const {
  return m_name;
}

float Player::GetSpeed() const {
  return m_speed;
}

void Player::HandleInput(const sf::Event& event) {
  m_state = std::move(m_state->HandleInput(*this, event));
}

void Player::Update(const sf::Time delta_time) {
  m_state->Update(*this, delta_time);
}

void Player::MoveLeft(float distance) {
  m_position.x -= distance;
}

void Player::MoveRight(float distance) {
  m_position.x += distance;
}
}  // namespace Game
