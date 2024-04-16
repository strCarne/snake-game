#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "Circle.hpp"
#include "DisplayObject.hpp"
#include "Ellipse.hpp"
#include "Line.hpp"
#include "RandomObjectParams.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include <random>

class Randomizer {
public:
  explicit Randomizer();

  sf::Vector3<uint8_t> color();

  sf::Vector2<int> point(int xLow, int xHigh, int yLow, int yHigh);

  int number(int low, int high);

  DisplayObject *rectangle(sf::Vector2<int> const &xRange,
                           sf::Vector2<int> const &yRange,
                           sf::Vector2<int> const &sizeRange);

  DisplayObject *rectangle(RandomObjectParams const &params);

  DisplayObject *circle(sf::Vector2<int> const &xRange,
                        sf::Vector2<int> const &yRange,
                        sf::Vector2<int> const &sizeRange);

  DisplayObject *circle(RandomObjectParams const &params);

  DisplayObject *ellipse(sf::Vector2<int> const &xRange,
                         sf::Vector2<int> const &yRange,
                         sf::Vector2<int> const &sizeRange);

  DisplayObject *ellipse(RandomObjectParams const &params);

  DisplayObject *line(sf::Vector2<int> const &xRange,
                      sf::Vector2<int> const &yRange,
                      sf::Vector2<int> const &sizeRange);

  DisplayObject *line(RandomObjectParams const &params);

  DisplayObject *triangle(sf::Vector2<int> const &xRange,
                          sf::Vector2<int> const &yRange,
                          sf::Vector2<int> const &sizeRange);

  DisplayObject *triangle(RandomObjectParams const &params);

private:
  std::mt19937 gen;

  // BT (border thickness) - ширина рамки
  static const int minBT = 0;
  static const int maxBT = 10;
};

#endif
