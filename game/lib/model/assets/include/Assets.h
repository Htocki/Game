#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Game {
class Assets {
 public:
  static Assets& Instance() {
    static Assets assets;
    return assets;
  }

  const sf::Font& GetFont() const;
  const sf::Texture& GetSpaceshipTexture() const;

 private:
  sf::Font m_font;
  sf::Texture m_spaceship;

  Assets();
  Assets(const Assets &) = delete;
  Assets &operator=(const Assets &) = delete;
};
}  // namespace Game
