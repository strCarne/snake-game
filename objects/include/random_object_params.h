#ifndef SNAKE_GAME__OBJECTS__RANDOM_OBJECT_PARAMS_H_
#define SNAKE_GAME__OBJECTS__RANDOM_OBJECT_PARAMS_H_

#include <SFML/Graphics.hpp>

struct RandomObjectParams {
  sf::Vector2<int> const &xRange;
  sf::Vector2<int> const &yRange;
  sf::Vector2<int> const &sizeRange;
};

#endif // SNAKE_GAME__OBJECTS__RANDOM_OBJECT_PARAMS_H_