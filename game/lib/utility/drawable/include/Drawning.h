#pragma once

#include <vector>

#include "Drawable.h"

namespace Game {
class Window;
class Drawning {
 public:
  virtual void Attach(Drawable* drawable);
  virtual void Detach(Drawable* drawable);
  virtual void Notify(Window* window);

 protected:
  Drawning() {}

 private:
  std::vector<Drawable*> m_drawables;
};
}  // namespace Game
