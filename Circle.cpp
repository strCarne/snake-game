#include "Circle.hpp"

Circle::Circle(int apX, int apY, int pX, int pY, int radius, int borderThickness, 
  uint8_t rFill, uint8_t gFill, uint8_t bFill, uint8_t rStroke, uint8_t gStroke, 
  uint8_t bStroke): DisplayObject(apX, apY, pX, pY, radius << 1, radius << 1, 
  borderThickness, rFill, gFill, bFill, rStroke, gStroke, bStroke) {
    this->radius = radius;
}

void Circle::draw(sf::RenderWindow &w) {
  sf::CircleShape primitive;
  primitive.setPosition({static_cast<float>(xClient1), 
    static_cast<float>(yClient1)});
  primitive.setRadius(radius);
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  w.draw(primitive);
}