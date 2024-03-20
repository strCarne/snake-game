#ifndef LINE_HPP
#define LINE_HPP

#include "DisplayObject.hpp"

class Line : public DisplayObject {
public:
  Line(sf::Vector2<int> const &ap, sf::Vector2<int> const &p1, 
    sf::Vector2<int> const &p2, sf::Vector3<uint8_t> const &color,
    bool drawBoundaries = false);

  void draw(sf::RenderWindow &w) override;

private:
    sf::VertexArray primitive;
};

#endif