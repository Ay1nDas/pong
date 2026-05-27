#pragma once
#include <SFML/Graphics.hpp>

bool AABB(sf::Vector2f objA, sf::Vector2f dimA, sf::Vector2f objB, sf::Vector2f dimB) {
  bool isColliding = (objA.x < objB.x + dimB.x);
  isColliding = isColliding && (objA.x + dimA.x > objB.x);
  isColliding = isColliding && (objA.y < objB.y + dimB.y);
  isColliding = isColliding && (objA.y + dimA.y > objB.y);

  return isColliding;
}
