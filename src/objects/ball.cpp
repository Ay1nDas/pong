#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "../constrants.hpp"

#include "ball.hpp"

Ball::Ball() :  speed({0, 0})
              , obj(sf::CircleShape(BALL_RADIUS)) {
  
  std::srand(std::time(nullptr));
  centreObject();
  setRandomSpeed();
  obj.setFillColor(sf::Color::White);
}

void Ball::centreObject() {
  float x = WINDOW_WIDTH / 2 - BALL_RADIUS;
  float y = WINDOW_HEIGHT / 2 - BALL_RADIUS;
  obj.setPosition({x, y});
}

void Ball::draw(sf::RenderWindow& window) {
  window.draw(obj);
}


void Ball::setRandomSpeed(sf::Vector2f multiplier) {
  int random_number = std::rand();
  speed.x = (random_number % 2) ? BALL_SPEED_X : - BALL_SPEED_X;
  speed.y = random_number % static_cast<int>(BALL_SPEED_X * 1.73) - BALL_SPEED_X * 1.73 / 2;
  speedMultiplier(multiplier);
}

void Ball::speedMultiplier(sf::Vector2f multiplier) {
  speed.x *= multiplier.x;
  speed.y *= multiplier.y;
}

void Ball::reset() {
  centreObject();
  speed.x = 0.f;
  speed.y = 0.f;
}

void Ball::setPosition(sf::Vector2f pos) {
  obj.setPosition(pos);
}

void Ball::move(float dx, float dy) {
  obj.move({dx, dy});
}

void Ball::updatePosition(const float dt) {
  float x = (speed.x * dt);
  float y = (speed.y * dt);
  obj.move({x, y});

  sf::Vector2f ballPos = obj.getPosition();
  if(ballPos.y < 0) {
    obj.setPosition({ballPos.x, 0});
    speedMultiplier({1.f, -1.03f});
  } else if(ballPos.y + 2 * BALL_RADIUS > WINDOW_HEIGHT) {
    obj.setPosition({ballPos.x, WINDOW_HEIGHT - 2 * BALL_RADIUS});
    speedMultiplier({1.f, -1.03f});
  }
}


sf::Vector2f Ball::getPosition() {
  return obj.getPosition();
}

sf::Vector2f Ball::getSpeed() {
  return speed;
}

const sf::CircleShape& Ball::getObject() {
  return obj;
}
