#include "Engine.h"

void Game::Engine::Update(sf::Time delta_time) {
  player.Update(delta_time);
  Notify();
}
