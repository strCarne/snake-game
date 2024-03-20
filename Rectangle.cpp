#include "Rectangle.hpp"

Rectangle::Rectangle(int apX, int apY, int pX, int pY, int width, int height, 
    int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
    uint8_t rStroke, uint8_t gStroke, uint8_t bStroke): DisplayObject(
    apX, apY, pX, pY, width, height, borderThickness, rFill, gFill, bFill, 
    rStroke, gStroke, bStroke) {
}

void Rectangle::draw(sf::RenderWindow &w) {
  sf::RectangleShape primitive;
  primitive.setPosition({static_cast<float>(xClient1), 
    static_cast<float>(yClient1)});
  primitive.setSize({static_cast<float>(xClient2 - xClient1), 
    static_cast<float>(yClient2 - yClient1)});
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  w.draw(primitive);
}