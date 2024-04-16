#include "Button.hpp"
#include "Controller.hpp"
#include "GameMap.hpp"
#include "Randomizer.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#define W_NAME "SnakeGG"
#define W_WIDTH 1000
#define W_HEIGHT 750
#define FPS_LIMIT 60

int main() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), W_NAME,
                          sf::Style::Default, settings);

  window.setFramerateLimit(60);

  sf::RectangleShape w_background({W_WIDTH, W_HEIGHT});
  w_background.setFillColor(sf::Color::White);
  int w_border = 10;

  sf::Font f;
  f.loadFromFile("BigBlueTerm.ttf");
  Button btn("Stop/Restart", f, 30, w_border + 10, W_HEIGHT - w_border - 45);
  btn.setFontColor(sf::Color::Red);
  btn.setStyle(sf::Text::Regular);

  GameMap gameMap(0, 0, 0 + w_border, 0 + w_border, W_WIDTH - (w_border << 1),
                  W_HEIGHT - (w_border << 1), 50, 0xFF, 0xFF, 0xFF, 0x24, 0x23,
                  0x24);

  sf::Vector3<uint8_t> c;
  Randomizer r;

  int w = 70;
  int h = 50;
  int d = 10;

  int x = gameMap.xClient1 + 20;
  int y = gameMap.yClient2 - 20 - h;

  c = r.color();
  gameMap.add(new Circle(0, 0, x, y, h >> 1, 0, 0, 0, 0, 4, c.x, c.y, c.z));
  gameMap.add(new Circle(0, 0, x, y, h >> 1, 0.1, 0, 0, 0, 4, c.x, c.y, c.z));
  gameMap.add(new Circle(0, 0, x, y, h >> 1, 0.1, 0,
                         Controller::DegreeToRadian(315), 0, 4, c.x, c.y, c.z));

  bool time_is_stopped = false;

  sf::Event event;
  sf::Clock clock;
  while (window.isOpen()) {
    if (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (btn.contains(sf::Mouse::getPosition(window))) {
            if (time_is_stopped) {
              clock.restart();
            }
            time_is_stopped ^= true;
          }
        }
        break;
      case sf::Event::Resized:
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        w_background.setSize({static_cast<float>(event.size.width),
                              static_cast<float>(event.size.height)});
        window.setView(sf::View(visibleArea));
        break;
      }
    }

    if (!time_is_stopped) {
      window.clear();
      window.draw(w_background);
      gameMap.draw(window);

      btn.update(window);
      gameMap.update(clock.getElapsedTime().asMilliseconds());
      window.display();
    }
  }
}