#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "DisplayObject.hpp"
#include "EllipseShape.hpp"

class Ellipse : public DisplayObject {
public:
  Ellipse(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    sf::Vector2<int> const &radius, int borderThickness, 
    sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0}, 
    bool drawBoundaries = false);

  void draw(sf::RenderWindow &w) override;

private:
  sf::EllipseShape primitive;
};

#endif