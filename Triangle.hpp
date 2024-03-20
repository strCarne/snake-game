#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "DisplayObject.hpp"
#include "Controller.hpp"

class Triangle : public DisplayObject {
public:
  Triangle(int apX, int apY, int p1X, int p1Y, int p2X, int p2Y, int p3X, 
    int p3Y, int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
    uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  void draw(sf::RenderWindow &w) override;

private:
  int p1X, p1Y, p2X, p2Y, p3X, p3Y;
};

#endif