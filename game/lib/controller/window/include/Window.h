#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Subject.h"

namespace Game {
class Window : public Subject {
public:
  Window();
  void HandleInput(const sf::Event& event);
  bool PollEvent(sf::Event& event);
  bool IsOpen() const;
  void Display();
  void Draw(const sf::Drawable& drawable);

private:
  sf::RenderWindow m_window;
};
}  // namespace Game
