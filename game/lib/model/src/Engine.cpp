#include "Engine.h"

Game::Engine::Engine() {
  Assets::Instance().Load();
}

void Game::Engine::Update(sf::Time deltaTime) {
  player.Update(deltaTime);
  Notify();
}
