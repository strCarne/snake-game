#include "Ellipse.hpp"

Ellipse::Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB, 
  int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
  uint8_t rStroke, uint8_t gStroke, uint8_t bStroke): DisplayObject(apX, apY, 
  pX, pY, radiusA << 1, radiusB << 1, borderThickness, rFill, gFill, bFill, 
  rStroke, gStroke, bStroke) {

  this->radiusA = radiusA;
  this->radiusB = radiusB;
}

void Ellipse::draw(sf::RenderWindow &w) {
  sf::EllipseShape primitive;
  primitive.setPosition({static_cast<float>(xClient1),
    static_cast<float>(yClient1)});
  primitive.setRadius({static_cast<float>(radiusA - borderThickness),
    static_cast<float>(radiusB - borderThickness)});
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  w.draw(primitive);
}