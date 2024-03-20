#include "Randomizer.hpp"

Randomizer::Randomizer() {
  std::random_device rd;
  gen = std::mt19937(rd());
}

sf::Vector3<uint8_t> Randomizer::color() {
  std::uniform_int_distribution<uint8_t> distr(0, 255);
  return {distr(gen), distr(gen), distr(gen)};
}

sf::Vector2<int> Randomizer::point(int xLow, int xHigh, int yLow, int yHigh) {
  return {number(xLow, xHigh), number(yLow, yHigh)};
}

int Randomizer::number(int low, int high) {
  std::uniform_int_distribution<int> distr(low, high);
  return distr(gen);
}

DisplayObject *Randomizer::rectangle(sf::Vector2<int> const &xRange,
  sf::Vector2<int> const &yRange, sf::Vector2<int> const &sizeRange) {
  
  int width = number(sizeRange.x, sizeRange.y);
  int height = number(sizeRange.x, sizeRange.y);
  
  sf::Vector2<int> p = point(xRange.x, xRange.y - width, 
    yRange.x, yRange.y - height);
  
  return new Rectangle({0, 0}, p, {width, height}, number(minBT, maxBT), color(), 
    color(), showBoundaries);
}

DisplayObject *Randomizer::rectangle(RandomObjectParams const &params) {
  return rectangle(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::circle(sf::Vector2<int> const &xRange,
  sf::Vector2<int> const &yRange,
  sf::Vector2<int> const &sizeRange) {
  
  int d = number(sizeRange.x,sizeRange.y);
  int r = d>>1;
  sf::Vector2<int> p = point(xRange.x, xRange.y - d, yRange.x, yRange.y - d);
  return new Circle({0, 0}, p, r, number(minBT, maxBT), color(), color(), 
    showBoundaries);
}

DisplayObject *Randomizer::circle(RandomObjectParams const &params) {
  return circle(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::ellipse(sf::Vector2<int> const &xRange,
  sf::Vector2<int> const &yRange,
  sf::Vector2<int> const &sizeRange) {

  int d1 = number(sizeRange.x,sizeRange.y);
  int d2 = number(sizeRange.x,sizeRange.y);

  sf::Vector2<int> r = {d1>>1, d2>>1};
  sf::Vector2<int> p = point(xRange.x, xRange.y - d1, yRange.x, yRange.y - d2);
  return new Ellipse({0, 0}, p, r, number(minBT, maxBT), color(), color(), 
    showBoundaries);
}

DisplayObject *Randomizer::ellipse(RandomObjectParams const &params) {
  return ellipse(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::line(sf::Vector2<int> const &xRange,
  sf::Vector2<int> const &yRange,
  sf::Vector2<int> const &sizeRange) {
  
  int width = number(sizeRange.x, sizeRange.y);
  int height = number(sizeRange.x, sizeRange.y);
  sf::Vector2<int> p1 = point(xRange.x, xRange.y - width, yRange.x, 
    yRange.y - height);
  sf::Vector2<int> p2 = {p1.x + width, p1.y + height};
  return new Line({0, 0}, p1, p2, color(), showBoundaries);
}

DisplayObject *Randomizer::line(RandomObjectParams const &params) {
  return line(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::triangle(sf::Vector2<int> const &xRange,
  sf::Vector2<int> const &yRange,
  sf::Vector2<int> const &sizeRange) {

  int width = number(sizeRange.x, sizeRange.y);
  int height = number(sizeRange.x, sizeRange.y);
  int x1 = number(xRange.x, xRange.y - width);
  int y1 = number(yRange.x, yRange.y - height);

  sf::Vector4<int> rect = {x1, y1, x1 + width, y1 + height};

  int wD = width / 5;
  int hD = height / 5;

  int wHalf = width / 2;
  int hHalf = height / 2;
  
  return new Triangle({0, 0}, 
    point(rect.x1, rect.x2 - wHalf - wD, rect.y1, rect.y2 - hHalf - hD),
    point(rect.x1 + wHalf + wD, rect.x2, rect.y1, rect.y2 - hHalf - hD),
    point(rect.x1, rect.x2 - wHalf - wD, rect.y1 + hHalf + hD, rect.y2), 
    number(minBT, maxBT), color(),
    color(), showBoundaries);

}

DisplayObject *Randomizer::triangle(RandomObjectParams const &params) {
  return triangle(params.xRange, params.yRange, params.sizeRange);
}