#pragma once

#include "entity.hpp"
#include "../constrants.hpp"

class Paddle : public Entity {
private:
  sf::RectangleShape obj;
  int mv;
public:
  Paddle(Direction::X pos);
  void centreObject() override;
  void draw(sf::RenderWindow& window) override;

  void move(float x, float y);
  void updatePosition(const float dt);
  void setMove(Direction::Y mov);

  sf::Vector2f getPosition();
};
