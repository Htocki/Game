
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
class RenderPlayer : public sf::Drawable, public sf::Transformable {
 public:
  RenderPlayer();
  void Render(const Player& player, sf::RenderWindow& window);

 private:
  void Update(const Player& player);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

  sf::Sprite m_spaceship;
};
}  // namespace Game
