#include <SFML/Graphics.hpp>

#include "constrants.hpp"
#include "game.hpp"
#include "objects/helper.hpp"

Game::Game() : player(Direction::X::LEFT),
               computer(Direction::X::RIGHT) {
  settings.antiAliasingLevel = 8;
  window.create(sf::VideoMode({800, 600}),
                "Pong",
                sf::Style::Default,
                sf::State::Windowed,
                settings);
  window.setVerticalSyncEnabled(true);
}

void Game::handleEvents() {
  while(const std::optional event = window.pollEvent()) {
    if(event->is<sf::Event::Closed>()) {
      window.close();
    } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
      switch (keyPressed->scancode) {
        case sf::Keyboard::Scancode::W :
          player.setMove(Direction::Y::UP);
          break;
        case sf::Keyboard::Scancode::S : 
          player.setMove(Direction::Y::DOWN);
          break;
        default:
          break;
      }
    } else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
      switch (keyReleased->scancode) {
        case sf::Keyboard::Scancode::W :
        case sf::Keyboard::Scancode::S :
          player.setMove(Direction::Y::NONE);
          break;
        default:
          break;
      }
    }
  }
}

void Game::computerMove() {
  float ballCentre = ball.getPosition().y + BALL_RADIUS;
  float computerPaddleY = computer.getPosition().y;

  if(ballCentre < computerPaddleY) {
    computer.setMove(Direction::Y::UP);
  } else if(ballCentre > computerPaddleY + PADDLE_WIDTH) {
    computer.setMove(Direction::Y::DOWN);
  } else {
    computer.setMove(Direction::Y::NONE);
  }
}

void Game::updateGame(float dt) {
  ball.updatePosition(dt);
  player.updatePosition(dt);
  computer.updatePosition(dt);
}

void Game::collision() {
  sf::Vector2f ballPos = ball.getPosition();
  sf::Vector2f playerPos = player.getPosition();
  sf::Vector2f computerPos = computer.getPosition();

  /* Player-Wall Collisions*/

  /* Player-Ball Collisions */
  if(AABB(ballPos, {2 * BALL_RADIUS, 2 * BALL_RADIUS}, 
          playerPos, {PADDLE_WIDTH, PADDLE_HEIGHT})) {
    ball.setPosition({PADDLE_WIDTH, ball.getPosition().y});
    ball.speedMultiplier({-1.03f, 1.0f});
  }

  /* Computer-Ball Collisions */
  if(AABB(ballPos, {2 * BALL_RADIUS, 2 * BALL_RADIUS}, 
          computerPos, {PADDLE_WIDTH, PADDLE_HEIGHT})) {
    ball.setPosition({WINDOW_WIDTH - (PADDLE_WIDTH + BALL_RADIUS * 2), ball.getPosition().y});
    ball.speedMultiplier({-1.03f, 1.0f});
  }

}

void Game::renderWindow() {
  ball.draw(window);
  player.draw(window);
  computer.draw(window);
}

void Game::run() {
  clock.restart();
  while(window.isOpen()) {
    handleEvents();
    computerMove();

    float deltaTime = clock.restart().asSeconds();
    updateGame(deltaTime);
    collision();

    window.clear();
    renderWindow();
    window.display();
  }
}
