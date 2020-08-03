#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Game {
class Assets {
 public:
  static Assets &Instance() {
    static Assets assets;
    return assets;
  }
  void Load();

  sf::Font font;
  sf::Texture spaceship;

 private:
  Assets() {}
  ~Assets() {}
  Assets(const Assets &) = delete;
  Assets &operator=(const Assets &) = delete;
};
}  // namespace Game
