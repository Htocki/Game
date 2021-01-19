#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Text.h"
#include "Window.h"

namespace Game {
class Button {
 public:
  Button(Window* window);
  void HandleEvent(const sf::Event& event);
  void Draw();
  
  void SetFillColor(const sf::Color& color);
  void SetOutlineColor(const sf::Color& color);
  void SetOutlineThickness(float thickness);
  void SetPosition(const sf::Vector2f& position);
  void SetSize(const sf::Vector2f& size);
  void SetTextString(const sf::String& string); 
  void SetTextCharacterSize(unsigned int size);
  void SetTextFillColor(const sf::Color& color);
  void SetTextFont(const sf::Font& font);
  void SetTextStyle(sf::Uint32 style);

  const sf::Color&    GetFillColor() const;
  const sf::Color&    GetOutlineColor() const;
  float               GetOutlineThickness() const;
  const sf::Vector2f& GetPosition() const;
  const sf::Vector2f& GetSize() const;
  const sf::String&   GetTextString() const;
  unsigned int        GetTextCharacterSize() const;
  const sf::Color&    GetTextFillColor() const;
  const sf::Font*     GetTextFont() const;
  sf::Uint32          GetTextStyle() const;

 private:
  bool IsInside(const sf::Vector2f& position);
  void SetTextInCenter(); 
  
  Window* m_window;
  sf::RectangleShape m_background;
  Text m_text;
};
}  // namespace Game
