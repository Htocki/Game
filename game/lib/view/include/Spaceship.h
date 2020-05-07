#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Assets.h"
#include "Player.h"

namespace Game {
class Spaceship {
 public:
  explicit Spaceship(Player& player);
  void Draw(sf::RenderWindow& window);

 private:
  Player& m_player;
  sf::Sprite m_spaceship;
};
}  // namespace Game
