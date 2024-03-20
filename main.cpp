#include <SFML/Graphics.hpp>
#include "GameMap.hpp"
#include "Randomizer.hpp"

#define W_NAME "SnakeGG"
#define W_WIDTH 1000
#define W_HEIGHT 750
#define FPS_LIMIT 60

int main() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 16;

  sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), W_NAME,
    sf::Style::Default, settings);

  window.setFramerateLimit(FPS_LIMIT);

  GameMap gameMap({0, 0}, {0, 0}, {W_WIDTH, W_HEIGHT}, 30, {0xFF, 0xFF, 0xFF}, 
    {0x24, 0x23, 0x24});

  Randomizer randomizer;

  const int numOfObjectsInClass = 10;

  RandomObjectParams params = {{gameMap.xClient1 + 2, gameMap.xClient2 - 2},
    {gameMap.yClient1 + 2, gameMap.yClient2 - 2}, {60, 100}};

  for (int i = 0; i < numOfObjectsInClass; i++) {
    gameMap.push(randomizer.rectangle(params));
    gameMap.push(randomizer.circle(params));
    gameMap.push(randomizer.ellipse(params));
    gameMap.push(randomizer.triangle(params));
    gameMap.push(randomizer.line(params));
  }

  sf::Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::Resized:
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
        break;
      }
    }

    window.clear();
      gameMap.draw(window);
    window.display();
  }
}