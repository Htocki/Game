#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Drawning.h"
#include "EventHandler.h"

namespace Game {
class Window : public Drawning, public EventHandler {
public:
  Window();
  void HandleEvent(const sf::Event& event) final;
  bool PollEvent(sf::Event* event);
  bool IsOpen() const;
  void DrawAllEntities();
  void DrawEntity(const sf::Drawable& drawable);

private:
  sf::RenderWindow m_window;
};
}  // namespace Game
