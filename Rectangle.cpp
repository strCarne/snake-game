#include "Rectangle.hpp"

Rectangle::Rectangle(sf::Vector2<int> const &ap, 
  sf::Vector2<int> const &p, sf::Vector2<int> const &size, 
  int borderThickness, sf::Vector3<uint8_t> const &color, 
  sf::Vector3<uint8_t> const &borderColor, bool drawBoundaries): DisplayObject(
    ap, p, size, borderThickness, color, borderColor, drawBoundaries) {

  primitive.setPosition({static_cast<float>(x1 + borderThickness), 
    static_cast<float>(y1 + borderThickness)});
  primitive.setSize({static_cast<float>(size.x - (borderThickness << 1)), 
    static_cast<float>(size.y - (borderThickness << 1))});
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
}

void Rectangle::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  if (drawBoundaries) {
    DisplayObject::renderBoundaries(w);
  }
}