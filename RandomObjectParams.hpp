#ifndef RANDOM_OBJECT_PARAMS_HPP
#define RANDOM_OBJECT_PARAMS_HPP

#include <SFML/Graphics.hpp>

struct RandomObjectParams {
  sf::Vector2<int> const &xRange;
  sf::Vector2<int> const &yRange;
  sf::Vector2<int> const &sizeRange;
  // sf::Vector2<double>
};

#endif