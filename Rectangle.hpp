#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "DisplayObject.hpp"

class Rectangle : public DisplayObject {
public:
  Rectangle(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    sf::Vector2<int> const &size, int borderThickness, 
    sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0},
    bool drawBoundaries = false);

  void draw(sf::RenderWindow &w) override;

private:
    sf::RectangleShape primitive;
};

#endif