#include "Game.hpp"

#include "GameField.hpp"
#include <objects>

Game::Game(std::string const w_name, int w_width, int w_height,
           int w_border_thickness, int fps_limit)
    : w_name_(w_name), w_width_(w_width), w_height_(w_height),
      w_border_thickness_(w_border_thickness), fps_limit_(fps_limit) {}

void Game::Run() const {
  sf::ContextSettings settings;
  settings.antialiasingLevel = kAntialiasingLevel;

  sf::RenderWindow window(sf::VideoMode(w_width_, w_height_), w_name_,
                           sf::Style::Default, settings);

  window.setFramerateLimit(60);

  sf::RectangleShape w_border(
      {static_cast<float>(w_width_), static_cast<float>(w_height_)});
  w_border.setFillColor(sf::Color::White);

  GameField game_field(0, 0, 0 + w_border_thickness_, 0 + w_border_thickness_,
                       w_width_ - (w_border_thickness_ << 1),
                       w_height_ - (w_border_thickness_ << 1), 25, 0xFF, 0xFF,
                       0xFF, 0x24, 0x23, 0x24);

  sf::Vector3<uint8_t> c;
  Randomizer r;

  int w = 70;
  int h = 50;
  int d = 10;

  int x = game_field.x1_client() + 20;
  int y = game_field.y2_client() - 20 - h;

  c = r.color();
  game_field.Add(new Circle(0, 0, x, y, h >> 1, 0, 0, 0, 0, 4, c.x, c.y, c.z));
  game_field.Add(
      new Circle(0, 0, x, y, h >> 1, 0.1, 0, 0, 0, 4, c.x, c.y, c.z));
  game_field.Add(new Circle(0, 0, x, y, h >> 1, 0.1, 0,
                            Controller::DegreeToRadian(315), 0, 4, c.x, c.y,
                            c.z));

  sf::Font font;
  font.loadFromFile("./resources/BigBlueTerm.ttf");
  sf::Text text("TEST_TEXT", font, 50);
  text.setPosition({50, 50});
  text.setFillColor(sf::Color::Red);

  sf::Event event;
  sf::Clock clock;
  while (window.isOpen()) {
    if (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::Resized: {
        sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        w_border.setSize({static_cast<float>(event.size.width),
                           static_cast<float>(event.size.height)});
        window.setView(sf::View(visibleArea));
      } break;
      }
    }

    window.clear();
    window.draw(w_border);
    game_field.Draw(window);
    window.draw(text);
    game_field.Update(clock.getElapsedTime().asMilliseconds());
    window.display();
  }
}