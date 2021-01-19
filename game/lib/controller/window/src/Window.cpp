#include "Window.h"

namespace Game {
Window::Window(sf::Vector2u size, sf::String title) 
    : m_width { size.x }
    , m_height { size.y }
{
  m_window.create(sf::VideoMode(m_width, m_height), title);
  m_window.setFramerateLimit(60);
}

void Window::HandleEvent(const sf::Event& event) {
  if (event.type == sf::Event::Closed) {
    m_window.close();
  }
}

bool Window::PollEvent(sf::Event* event) {
  return m_window.pollEvent(*event);
}

bool Window::IsOpen() const { 
  return m_window.isOpen(); 
}

void Window::Clear() {
  m_window.clear();
}

void Window::Draw(const sf::Drawable& drawable) {
  m_window.draw(drawable);
}

void Window::Display() {
  m_window.display();
}

sf::Vector2f Window::MapPixelToCoords(sf::Vector2i window_pos) {
  return m_window.mapPixelToCoords(window_pos);
}

const sf::RenderWindow& Window::Get() const {
  return m_window;
}

sf::Vector2u Window::GetSize() const {
  return m_window.getSize();
}
}  // namespace Game
