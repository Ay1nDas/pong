#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Ball : public Entity {
private:
  sf::Vector2f speed;
  sf::CircleShape obj;

public:
  Ball();
  void centreObject() override;
  void draw(sf::RenderWindow& window) override;

  void setRandomSpeed(sf::Vector2f multiplier = {1.f, 1.f});
  void speedMultiplier(sf::Vector2f multiplier);
  void reset();
  void setPosition(sf::Vector2f pos);
  void move(float dx, float dy);
  void updatePosition(const float dt);

  sf::Vector2f getPosition();
  sf::Vector2f getSpeed();
  const sf::CircleShape& getObject();
};
