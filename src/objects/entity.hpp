#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
  virtual void centreObject() = 0;
  virtual void draw(sf::RenderWindow& window) = 0;
};
