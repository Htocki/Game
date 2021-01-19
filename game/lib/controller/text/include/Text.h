#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>

#include "Window.h"

namespace Game {
class Text {
 public:
  Text(Window* window);
  
  void Draw();
  
  void SetCharacterSize(unsigned int size);
  void SetFillColor(const sf::Color& color);
  void SetFont(const sf::Font& font);
  void SetPosition(const sf::Vector2f& position);
  void SetString(const sf::String& string);
  void SetStyle(sf::Uint32 style);
  
  unsigned int        GetCharacterSize() const;
  const sf::Color&    GetFillColor() const;
  const sf::Font*     GetFont() const;
  const sf::Vector2f& GetPosition() const;
  const sf::Vector2f  GetSize() const;
  const sf::String&   GetString() const;
  sf::Uint32          GetStyle() const;

 private:
  Window* m_window;
  sf::Text m_text;
};
}  // namespace Game
