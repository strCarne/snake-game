#ifndef SNAKE_GAME__OBJECTS__CONTROLLER_H_
#define SNAKE_GAME__OBJECTS__CONTROLLER_H_

#include <SFML/Graphics.hpp>

#include "vector4.h"

class Controller {
public:
  static double CalcEuclideanDistance(sf::Vector2<int> const &p1,
                                      sf::Vector2<int> const &p2);
  static double CalcEuclideanDistance(sf::Vector2<float> const &p1,
                                      sf::Vector2<float> const &p2);

  static double CalcEuclideanDistance(double v1, double v2);

  static bool FpvAreEqual(float v1, float v2);
  static bool FpvAreEqual(double v1, double v2);

  static sf::Vector4<int> GetParallelLine(sf::Vector4<int> const &line, int d);

  static sf::Vector4<int>
  GetClosestToApParallelLine(sf::Vector2<int> const &ap,
                             sf::Vector4<int> const &line, int d);

  static sf::Vector2<int> GetLinesIntersection(sf::Vector4<int> const &line1,
                                               sf::Vector4<int> &line2);

  static int CalcPosition(int s0, double v0, double a, int t);

  static double CalcAngle(double x, double y);

  static double DegreeToRadian(double angle);
  static double RadianToDegree(double angle);

  static double ProjectOnX(double value, double alpha);
  static double ProjectOnY(double value, double alpha);

  static double fpvMod(double value, int mod) {
    int v = value;
    return v % mod + value - v;
  }

private:
  static sf::Vector2<int> GetParallelPoint(sf::Vector2<int> const &v,
                                           sf::Vector2<int> const &ap, int d);

  static constexpr double EPSILON = 0.001;
};

#endif // SNAKE_GAME__OBJECTS__CONTROLLER_H_