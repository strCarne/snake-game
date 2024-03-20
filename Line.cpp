#include "Line.hpp"

Line::Line(sf::Vector2<int> const &ap, sf::Vector2<int> const &p1, 
  sf::Vector2<int> const &p2, sf::Vector3<uint8_t> const &color,
  bool drawBoundaries): DisplayObject(ap, p1, {p2.x - p1.x, p2.y - p1.y}, 0, 
  color, {255, 255, 255}, drawBoundaries) {

  primitive = sf::VertexArray(sf::Lines, 2);
  primitive[0].position = {static_cast<float>(xClient1), 
    static_cast<float>(yClient1)};
  primitive[0].color = sf::Color(r, g, b);
  primitive[1].position = {static_cast<float>(xClient2), 
    static_cast<float>(yClient2)};
  primitive[1].color = sf::Color(r, g, b);
}

void Line::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  if (drawBoundaries) {
    renderBoundaries(w);
  }
}