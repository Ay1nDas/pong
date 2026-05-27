#pragma once

inline constexpr int WINDOW_WIDTH = 800;
inline constexpr int WINDOW_HEIGHT = 600;

inline constexpr float BALL_RADIUS = 10.f;
inline constexpr float BALL_SPEED_X = 200.f;

inline constexpr float PADDLE_HEIGHT = 120.f;
inline constexpr float PADDLE_WIDTH = 15.f;
inline constexpr float PADDLE_SPEED = 200.f;

namespace Direction {
  enum class X {
    LEFT,
    RIGHT,
    NONE
  };
  
  enum class Y {
    UP,
    DOWN,
    NONE
  };
}
