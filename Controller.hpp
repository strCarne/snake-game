#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include "Vector4.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>

class Controller {
public:
  static double calcEuclideanDistance(sf::Vector2<int> const &p1,
                                      sf::Vector2<int> const &p2);

  static double calcEuclide(double v1, double v2);

  static bool fpvAreEqual(float v1, float v2);
  static bool fpvAreEqual(double v1, double v2);

  static sf::Vector4<int> getParallelLine(sf::Vector4<int> const &line, int d);

  static sf::Vector4<int>
  getClosestToApParallelLine(sf::Vector2<int> const &ap,
                             sf::Vector4<int> const &line, int d);

  static sf::Vector2<int> getLinesIntersection(sf::Vector4<int> const &line1,
                                               sf::Vector4<int> &line2);

  static int calcPosition(int s0, double v0, double a, int t);

  static double calcAngle(double x, double y);

  static double DegreeToRadian(double angle);

  static double ProjectOnX(double value, double alpha);
  static double ProjectOnY(double value, double alpha);

private:
  static sf::Vector2<int> getParallelPoint(sf::Vector2<int> const &v,
                                           sf::Vector2<int> const &ap, int d);

  static constexpr double EPSILON = 0.001;
};

#endif