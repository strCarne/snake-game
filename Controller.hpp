#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>
#include "Vector4.hpp"

class Controller {
public:
  static double calcEuclideanDistance(sf::Vector2<int> const &p1, 
    sf::Vector2<int> const &p2);

  static bool fpvAreEqual(float v1, float v2);
  static bool fpvAreEqual(double v1, double v2);

  static sf::Vector4<int> getParallelLine(sf::Vector4<int> const &line, int d);

  static sf::Vector4<int> getClosestToApParallelLine(sf::Vector2<int> const &ap,
    sf::Vector4<int> const &line, int d);

  static sf::Vector2<int> getLinesIntersection(sf::Vector4<int> const &line1,
    sf::Vector4<int> &line2);

private:
  static sf::Vector2<int> getParallelPoint(sf::Vector2<int> const &v, 
    sf::Vector2<int> const &ap, int d);

  static constexpr double EPSILON = 0.001;
};

#endif