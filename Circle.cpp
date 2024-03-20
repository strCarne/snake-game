#include "Circle.hpp"

Circle::Circle(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
  int radius, int borderThickness, sf::Vector3<uint8_t> const &color, 
  sf::Vector3<uint8_t> const &borderColor, bool drawBoundaries): DisplayObject(
  ap, p, {radius << 1, radius << 1}, borderThickness, color, borderColor, 
  drawBoundaries) {

  primitive.setPosition({static_cast<float>(p.x + borderThickness), 
    static_cast<float>(p.y + borderThickness)});
  primitive.setRadius(static_cast<float>(radius - borderThickness));
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
}

void Circle::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  if (drawBoundaries) {
    DisplayObject::renderBoundaries(w);
  }
}