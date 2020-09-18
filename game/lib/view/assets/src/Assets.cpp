#include "Assets.h"

#include <exception>

namespace Game {
Assets::Assets() {
  if (!m_font.loadFromFile("media/fonts/Sansation.ttf")) {
    throw std::invalid_argument {
      "File \"media/fonts/Sansation.ttf\" not found."
    };
  }

  if (!m_spaceship.loadFromFile("media/textures/Spaceship.png")) {
    throw std::invalid_argument {
      "File \"media/textures/Spaceship.png\" not found."
    };
  }
}

const sf::Font& Assets::GetFont() const {
  return m_font;
}

const sf::Texture& Assets::GetSpaceshipTexture() const {
  return m_spaceship;
}

}  // namespace Game
