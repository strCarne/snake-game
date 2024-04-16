#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "DisplayObject.hpp"
#include "EllipseShape.hpp"

class Ellipse : public DisplayObject {
public:
  Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB,
          int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
          uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB,
          double v0X, double v0Y, double aX, double aY, int createdAt,
          int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
          uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB, double v,
          double a, double dir, int createdAt, int borderThickness,
          uint8_t rFill, uint8_t gFill, uint8_t bFill, uint8_t rStroke = 0,
          uint8_t gStroke = 0, uint8_t bStroke = 0);

  void draw(sf::RenderWindow &w) override;

private:
  int radiusA, radiusB;
};

#endif