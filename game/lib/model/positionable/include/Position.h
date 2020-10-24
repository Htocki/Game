#pragma once

namespace Game {
struct Position {
  float x = 0.f;
  float y = 0.f;
};

inline bool operator==(const Position& l, const Position& r) {
  return l.x == r.x && l.y == r.y;
}

inline bool operator!=(const Position& l, const Position& r) {
  return !operator==(l, r);
}
}  // namespace Game
