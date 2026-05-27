#pragma once

#include "objects/ball.hpp"
#include "objects/paddle.hpp"

class Game {
private:
  sf::RenderWindow window;
  sf::Clock clock;
  sf::ContextSettings settings;

  Paddle player;
  Paddle computer;
  Ball ball;

  void handleEvents();
  void computerMove();
  void updateGame(float dt);
  void collision();
  void renderWindow();

public:
  Game();
  void run();
};
