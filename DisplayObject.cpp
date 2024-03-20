#include "DisplayObject.hpp"

DisplayObject::DisplayObject(sf::Vector2<int> const &ap, 
  sf::Vector2<int> const &p, sf::Vector2<int> const &size, 
  int borderThickness, sf::Vector3<uint8_t> const &color, 
  sf::Vector3<uint8_t> const &borderColor, bool drawBoundaries) {
  
  xAP = ap.x;
  yAP = ap.y;

  x1 = p.x;
  y1 = p.y;
  x2 = x1 + size.x;
  y2 = y1 + size.y;

  xClient1 = x1 + borderThickness;
  yClient1 = y1 + borderThickness;
  xClient2 = x2 - borderThickness;
  yClient2 = y2 - borderThickness;

  this->borderThickness = borderThickness;

  r = color.x;
  g = color.y;
  b = color.z;

  rB = borderColor.x;
  bB = borderColor.y;
  gB = borderColor.z;

  this->drawBoundaries = drawBoundaries;

  updateBoundaries();
}

void DisplayObject::renderBoundaries(sf::RenderWindow &w) {
  w.draw(boundaries);
}

void DisplayObject::updateBoundaries() {
  boundaries.setPosition({static_cast<float>(x1), static_cast<float>(y1)});
  boundaries.setSize({static_cast<float>(x2 - x1), static_cast<float>(y2 - y1)});
  boundaries.setFillColor(sf::Color::Transparent);
  boundaries.setOutlineThickness(boundaryThickness);
  boundaries.setOutlineColor(sf::Color::Red);
}