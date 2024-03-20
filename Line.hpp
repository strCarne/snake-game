#ifndef LINE_HPP
#define LINE_HPP

#include "DisplayObject.hpp"

class Line : public DisplayObject {
public:
  Line(int apX, int apY, int p1X, int p1Y, int p2X, int p2Y, uint8_t rFill, 
  uint8_t gFill, uint8_t bFill);

  void draw(sf::RenderWindow &w) override;
};

#endif