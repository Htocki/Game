#include "Assets.h"

void Game::Assets::Load() {
  if (!font.loadFromFile("media/fonts/Sansation.ttf")) {
    throw LoadingFail{};
  }

  if (!spaceship.loadFromFile("media/textures/Spaceship.png")) {
    throw LoadingFail{};
  }
}
