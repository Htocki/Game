#include "Drawning.h"

#include <algorithm>

#include "Window.h"

namespace Game {
void Drawning::Attach(Drawable* drawable) {
  m_drawables.push_back(drawable);
}

void Drawning::Detach(Drawable* drawable) {
  auto new_end = std::remove(
    std::begin(m_drawables),
    std::end(m_drawables),
    drawable);
  m_drawables.erase(new_end, m_drawables.end());
}

void Drawning::Notify(Window* window) {
  for (auto* drawable : m_drawables) {
    drawable->Draw(window);
  }
}
}  // namespace Game
