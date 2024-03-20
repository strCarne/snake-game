#include "Controller.hpp"

double Controller::calcEuclideanDistance(sf::Vector2<int> const &p1,
  sf::Vector2<int> const &p2) {

  int dX = p2.x - p1.x;
  int dY = p2.y - p1.y;

  return std::sqrt(dX * dX + dY * dY);
}

bool Controller::fpvAreEqual(float v1, float v2) {
  return std::abs(v2 - v1) < EPSILON;
}

bool Controller::fpvAreEqual(double v1, double v2) {
  return std::abs(v2 - v1) < EPSILON;
}

sf::Vector4<int> Controller::getParallelLine(sf::Vector4<int> const &line,
  int d) {
  
  sf::Vector2<int> v = {line.x2 - line.x1, line.y2 - line.y1};

  sf::Vector2<int> p1 = getParallelPoint(v, {line.x1, line.y1}, d);  
  sf::Vector2<int> p2 = getParallelPoint(v, {line.x2, line.y2}, d);

  return {p1.x, p1.y, p2.x, p2.y};
}

sf::Vector4<int> Controller::getClosestToApParallelLine(
  sf::Vector2<int> const &ap, sf::Vector4<int> const &line, int d) {

  sf::Vector2<int> v = {line.x2 - line.x1, line.y2 - line.y1};

  sf::Vector2<int> p1 = getParallelPoint(v, {line.x1, line.y1}, d);
  sf::Vector2<int> tmpP1 = getParallelPoint(v, {line.x1, line.y1}, -d);

  double d1 = calcEuclideanDistance(ap, p1);
  double d2 = calcEuclideanDistance(ap, tmpP1);

  if (d2 < d1) {
    d = -d;
    p1 = tmpP1;
  }

  sf::Vector2<int> p2 = getParallelPoint(v, {line.x2, line.y2}, d);

  return {p1.x, p1.y, p2.x, p2.y};
}

sf::Vector2<int> Controller::getParallelPoint(sf::Vector2<int> const &v,
  sf::Vector2<int> const &ap, int d) {
  
  sf::Vector2<double> n = {(double)v.y, (double)-v.x};
  
  double l = std::sqrt(n.x * n.x + n.y * n.y);
  
  n.x /= l;
  n.y /= l;
  
  n.x *= d;
  n.y *= d;
  
  return {ap.x + (int)n.x, ap.y + (int)n.y};
}

sf::Vector2<int> Controller::getLinesIntersection(
  sf::Vector4<int> const &l1, sf::Vector4<int> &l2) {

  int a1 = l1.y2 - l1.y1;
  int b1 = l1.x1 - l1.x2;
  int c1 = a1 * l1.x1 + b1 * l1.y1;

  int a2 = l2.y2 - l2.y1;
  int b2 = l2.x1 - l2.x2;
  int c2 = a2 * l2.x1 + b2 * l2.y1;

  int det = a1 * b2 - a2 * b1;

  if (det == 0) {
    throw std::invalid_argument("parallel lines");
  }

  int x = (b2*c1 - b1*c2)/det;
  int y = (a1*c2 - a2*c1)/det;

  return {x, y};
}