#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "DisplayObject.hpp"

class Circle : public DisplayObject {
public:
  Circle(int apX, int apY, int pX, int pY, int radius, int borderThickness,
         uint8_t rFill, uint8_t gFill, uint8_t bFill, uint8_t rStroke = 0,
         uint8_t gStroke = 0, uint8_t bStroke = 0);

  Circle(int apX, int apY, int pX, int pY, int radius, double v0X, double v0Y,
         double aX, double aY, int createdAt, int borderThickness,
         uint8_t rFill, uint8_t gFill, uint8_t bFill, uint8_t rStroke = 0,
         uint8_t gStroke = 0, uint8_t bStroke = 0);

  Circle(int apX, int apY, int pX, int pY, int radius, double v, double a,
         double dir, int createdAt, int borderThickness, uint8_t rFill,
         uint8_t gFill, uint8_t bFill, uint8_t rStroke = 0, uint8_t gStroke = 0,
         uint8_t bStroke = 0);

  void draw(sf::RenderWindow &w) override;

private:
  int radius;
};

#endif // !CIRCLE_HPP