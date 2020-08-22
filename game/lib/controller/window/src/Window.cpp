#include "Window.h"

namespace Game {
Window::Window() {
  m_window.create(sf::VideoMode(600, 600), "Name");
  m_window.setFramerateLimit(60);
}

void Window::HandleInput(const sf::Event& event) {
  if (event.type == sf::Event::Closed) {
    m_window.close();
  }
}

bool Window::PollEvent(sf::Event& event) {
  return m_window.pollEvent(event);
}

bool Window::IsOpen() const { 
  return m_window.isOpen(); 
}

void Window::Display() {
  m_window.clear();
  Notify(*this);
  m_window.display();
}

void Window::Draw(const sf::Drawable& drawable) {
  m_window.draw(drawable);
}
}  // namespace Game
