#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "DisplayObject.hpp"

class Rectangle : public DisplayObject {
public:
  Rectangle(int apX, int apY, int pX, int pY, int width, int height, 
    int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
    uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  void draw(sf::RenderWindow &w) override;
};

#endif