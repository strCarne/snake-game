#include "Line.hpp"

Line::Line(int apX, int apY, int p1X, int p1Y, int p2X, int p2Y, uint8_t rFill, 
  uint8_t gFill, uint8_t bFill): DisplayObject(apX, apY, p1X, p1Y, p2X - p1X, 
  p2Y - p1Y, 0, rFill, gFill, bFill, 255, 255, 255) {}

void Line::draw(sf::RenderWindow &w) {
  sf::VertexArray primitive(sf::Lines, 2);
  primitive[0].position = {static_cast<float>(xClient1), 
    static_cast<float>(yClient1)};
  primitive[0].color = sf::Color(r, g, b);
  primitive[1].position = {static_cast<float>(xClient2), 
    static_cast<float>(yClient2)};
  primitive[1].color = sf::Color(r, g, b);
  w.draw(primitive);
}