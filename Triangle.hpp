#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "DisplayObject.hpp"
#include "Controller.hpp"

class Triangle : public DisplayObject {
public:
  Triangle(sf::Vector2<int> const &ap, sf::Vector2<int> const &p1, 
    sf::Vector2<int> const &p2, sf::Vector2<int> const &p3, 
    int borderThickness, sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0},
    bool drawBoundaries = false);

  void draw(sf::RenderWindow &w) override;

private:
    sf::ConvexShape primitive;
};

#endif