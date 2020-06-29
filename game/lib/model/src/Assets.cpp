#include "Assets.h"

#include <exception>

namespace Game {
void Assets::Load() {
  if (!font.loadFromFile("media/fonts/Sansation.ttf")) {
    throw std::invalid_argument {
      "File \"media/fonts/Sansation.ttf\" not found."
    };
  }

  if (!spaceship.loadFromFile("media/textures/Spaceship.png")) {
    throw std::invalid_argument {
      "File \"media/textures/Spaceship.png\" not found."
    };
  }
}
}  // namespace Game

