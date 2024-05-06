#include "controller.h"

#include <cmath>
#include <cstdlib>

double Controller::CalcEuclideanDistance(sf::Vector2<int> const &p1,
                                         sf::Vector2<int> const &p2) {

  auto dX = p2.x - p1.x;
  auto dY = p2.y - p1.y;

  return CalcEuclideanDistance(dX, dY);
}

double Controller::CalcEuclideanDistance(sf::Vector2<float> const &p1,
                                         sf::Vector2<float> const &p2) {
  auto dX = p2.x - p1.x;
  auto dY = p2.y - p1.y;

  return CalcEuclideanDistance(dX, dY);
}

bool Controller::FpvAreEqual(float v1, float v2) {
  return std::abs(v2 - v1) < EPSILON;
}

bool Controller::FpvAreEqual(double v1, double v2) {
  return std::abs(v2 - v1) < EPSILON;
}

sf::Vector4<int> Controller::GetParallelLine(sf::Vector4<int> const &line,
                                             int d) {

  sf::Vector2<int> v = {line.x2_ - line.x1_, line.y2_ - line.y1_};

  sf::Vector2<int> p1 = GetParallelPoint(v, {line.x1_, line.y1_}, d);
  sf::Vector2<int> p2 = GetParallelPoint(v, {line.x2_, line.y2_}, d);

  return {p1.x, p1.y, p2.x, p2.y};
}

sf::Vector4<int>
Controller::GetClosestToApParallelLine(sf::Vector2<int> const &ap,
                                       sf::Vector4<int> const &line, int d) {

  sf::Vector2<int> v = {line.x2_ - line.x1_, line.y2_ - line.y1_};

  sf::Vector2<int> p1 = GetParallelPoint(v, {line.x1_, line.y1_}, d);
  sf::Vector2<int> tmpP1 = GetParallelPoint(v, {line.x1_, line.y1_}, -d);

  double d1 = CalcEuclideanDistance(ap, p1);
  double d2 = CalcEuclideanDistance(ap, tmpP1);

  if (d2 < d1) {
    d = -d;
    p1 = tmpP1;
  }

  sf::Vector2<int> p2 = GetParallelPoint(v, {line.x2_, line.y2_}, d);

  return {p1.x, p1.y, p2.x, p2.y};
}

double Controller::CalcEuclideanDistance(double v1, double v2) {
  return std::sqrt(std::pow(v1, 2) + std::pow(v2, 2));
}

sf::Vector2<int> Controller::GetParallelPoint(sf::Vector2<int> const &v,
                                              sf::Vector2<int> const &ap,
                                              int d) {

  sf::Vector2<double> n = {(double)v.y, (double)-v.x};

  double l = std::sqrt(n.x * n.x + n.y * n.y);

  n.x /= l;
  n.y /= l;

  n.x *= d;
  n.y *= d;

  return {ap.x + (int)n.x, ap.y + (int)n.y};
}

sf::Vector2<int> Controller::GetLinesIntersection(sf::Vector4<int> const &line1,
                                                  sf::Vector4<int> &line2) {

  int a1 = line1.y2_ - line1.y1_;
  int b1 = line1.x1_ - line1.x2_;
  int c1 = a1 * line1.x1_ + b1 * line1.y1_;

  int a2 = line2.y2_ - line2.y1_;
  int b2 = line2.x1_ - line2.x2_;
  int c2 = a2 * line2.x1_ + b2 * line2.y1_;

  int det = a1 * b2 - a2 * b1;

  if (det == 0) {
    throw std::invalid_argument("parallel lines");
  }

  int x = (b2 * c1 - b1 * c2) / det;
  int y = (a1 * c2 - a2 * c1) / det;

  return {x, y};
}

int Controller::CalcPosition(int s0, double v0, double a, int t) {
  return round(s0 + v0 * t + a * t * t / 2);
}

double Controller::CalcAngle(double x, double y) {
  bool x_is_pos = x >= 0;
  bool y_is_pos = y >= 0;

  x = std::abs(x);
  y = std::abs(y);

  double angle_x = std::atan(y / x);
  double angle_y = M_PI_2 - angle_x;

  if (x_is_pos && y_is_pos) {
    return angle_x;
  }

  if (!x_is_pos && !y_is_pos) {
    return angle_x + M_PI;
  }

  if (!x_is_pos && y_is_pos) {
    return angle_x + (angle_y * 2);
  }

  return angle_x + M_PI + (angle_y * 2);
}

double Controller::DegreeToRadian(double angle) { return angle * M_PI / 180; }

double Controller::RadianToDegree(double angle) { return angle * 180 / M_PI; }

double Controller::ProjectOnX(double value, double alpha) {
  return value * std::cos(alpha);
}

double Controller::ProjectOnY(double value, double alpha) {
  return value * std::sin(alpha);
}
