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
                                     sf::Vector2<int> const &yRange,
                                     sf::Vector2<int> const &sizeRange) {

  int width = number(sizeRange.x, sizeRange.y);
  int height = number(sizeRange.x, sizeRange.y);

  sf::Vector2<int> p =
      point(xRange.x, xRange.y - width, yRange.x, yRange.y - height);

  sf::Vector3<uint8_t> f = color();
  sf::Vector3<uint8_t> b = color();

  return new Rectangle(0, 0, p.x, p.y, width, height, number(minBT, maxBT), f.x,
                       f.y, f.z, b.x, b.y, b.z);
}

DisplayObject *Randomizer::rectangle(RandomObjectParams const &params) {
  return rectangle(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::circle(sf::Vector2<int> const &xRange,
                                  sf::Vector2<int> const &yRange,
                                  sf::Vector2<int> const &sizeRange) {

  int d = number(sizeRange.x, sizeRange.y);
  int r = d >> 1;
  sf::Vector2<int> p = point(xRange.x, xRange.y - d, yRange.x, yRange.y - d);

  sf::Vector3<uint8_t> f = color();
  sf::Vector3<uint8_t> b = color();

  return new Circle(0, 0, p.x, p.y, r, number(minBT, maxBT), f.x, f.y, f.z, b.x,
                    b.y, b.z);
}

DisplayObject *Randomizer::circle(RandomObjectParams const &params) {
  return circle(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::ellipse(sf::Vector2<int> const &xRange,
                                   sf::Vector2<int> const &yRange,
                                   sf::Vector2<int> const &sizeRange) {

  int d1 = number(sizeRange.x, sizeRange.y);
  int d2 = number(sizeRange.x, sizeRange.y);

  sf::Vector2<int> p = point(xRange.x, xRange.y - d1, yRange.x, yRange.y - d2);

  sf::Vector3<uint8_t> f = color();
  sf::Vector3<uint8_t> b = color();

  return new Ellipse(0, 0, p.x, p.y, d1 >> 1, d2 >> 1, number(minBT, maxBT),
                     f.x, f.y, f.z, b.x, b.y, b.z);
}

DisplayObject *Randomizer::ellipse(RandomObjectParams const &params) {
  return ellipse(params.xRange, params.yRange, params.sizeRange);
}

DisplayObject *Randomizer::line(sf::Vector2<int> const &xRange,
                                sf::Vector2<int> const &yRange,
                                sf::Vector2<int> const &sizeRange) {

  int width = number(sizeRange.x, sizeRange.y);
  int height = number(sizeRange.x, sizeRange.y);
  sf::Vector2<int> p1 =
      point(xRange.x, xRange.y - width, yRange.x, yRange.y - height);
  sf::Vector2<int> p2 = {p1.x + width, p1.y + height};

  sf::Vector3<uint8_t> f = color();

  return new Line(0, 0, p1.x, p1.y, p2.x, p2.y, f.x, f.y, f.z);
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

  sf::Vector2<int> p1 =
      point(rect.x1_, rect.x2_ - wHalf - wD, rect.y1_, rect.y2_ - hHalf - hD);
  sf::Vector2<int> p2 =
      point(rect.x1_ + wHalf + wD, rect.x2_, rect.y1_, rect.y2_ - hHalf - hD);
  sf::Vector2<int> p3 =
      point(rect.x1_, rect.x2_ - wHalf - wD, rect.y1_ + hHalf + hD, rect.y2_);

  sf::Vector3<uint8_t> f = color();
  sf::Vector3<uint8_t> b = color();

  return new Triangle(0, 0, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y,
                      number(minBT, maxBT), f.x, f.y, f.z, b.x, b.y, b.z);
}

DisplayObject *Randomizer::triangle(RandomObjectParams const &params) {
  return triangle(params.xRange, params.yRange, params.sizeRange);
}