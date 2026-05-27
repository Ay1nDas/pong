#include "../constrants.hpp"

#include "paddle.hpp"

Paddle::Paddle(Direction::X pos) : mv(0), obj({PADDLE_WIDTH, PADDLE_HEIGHT}) {
  centreObject();
  obj.setFillColor(sf::Color::White);

  if(pos == Direction::X::LEFT) {
    obj.setPosition({0, obj.getPosition().y});
  } else if(pos == Direction::X::RIGHT) {
    obj.setPosition({WINDOW_WIDTH - PADDLE_WIDTH, obj.getPosition().y});
  } else {
    throw Direction::X::NONE;
  }
}

void Paddle::centreObject() {
  obj.setPosition({obj.getPosition().x, WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2});
}

void Paddle::draw(sf::RenderWindow& window) {
  window.draw(obj);
}


void Paddle::move(float x, float y) {
  obj.move({x, y});
}

void Paddle::updatePosition(const float dt) {
  obj.move({0.f, PADDLE_SPEED * dt * mv});

  float paddleY = obj.getPosition().y;
  if(paddleY < 0.f) {
    paddleY = 0.f;
  } else if (paddleY > WINDOW_HEIGHT - PADDLE_HEIGHT) {
    paddleY = WINDOW_HEIGHT - PADDLE_HEIGHT;
  }
  obj.setPosition({obj.getPosition().x, paddleY});
}

void Paddle::setMove(Direction::Y mov) {
  switch(mov) {
    case Direction::Y::NONE:
      mv = 0;
      break;
    case Direction::Y::UP :
      mv = -1;
      break;
    case Direction::Y::DOWN :
      mv = 1;
      break;
    default:
      break;
  }
}

sf::Vector2f Paddle::getPosition() {
  return obj.getPosition();
}

