#include "Ellipse.hpp"

Ellipse::Ellipse(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    sf::Vector2<int> const &radius, int borderThickness, 
    sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor, bool drawBoundaries): 
    DisplayObject(ap, p, {radius.x << 1, radius.y << 1}, borderThickness, color, 
    borderColor, drawBoundaries) {

  primitive.setPosition({static_cast<float>(xClient1),
    static_cast<float>(yClient1)});
  primitive.setRadius({static_cast<float>(radius.x - borderThickness),
    static_cast<float>(radius.y - borderThickness)});
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
}

void Ellipse::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  if (drawBoundaries) {
    DisplayObject::renderBoundaries(w);
  }
}