#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

namespace Game {
class Window {
public:
  Window(sf::Vector2u size, sf::String title);
  void HandleEvent(const sf::Event& event);
  bool PollEvent(sf::Event* event);
  bool IsOpen() const;
  void Clear();
  void Draw(const sf::Drawable& drawable);
  void Display();
  sf::Vector2f MapPixelToCoords(sf::Vector2i window_pos);
  const sf::RenderWindow& Get() const;
  sf::Vector2u GetSize() const;

private:
  unsigned int m_width;
  unsigned int m_height;
  sf::RenderWindow m_window;
};
}  // namespace Game
