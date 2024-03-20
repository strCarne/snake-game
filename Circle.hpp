#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "DisplayObject.hpp"

class Circle : public DisplayObject {
public:
  Circle(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    int radius, int borderThickness, sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0}, 
    bool drawBoundaries = false);

  void draw(sf::RenderWindow &w) override;

private:
  sf::CircleShape primitive;
};

#endif // !CIRCLE_HPP