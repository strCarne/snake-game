#ifndef CONSTRUCT_PARAMS_HPP
#define CONSTRUCT_PARAMS_HPP

#include "DisplayObject.hpp"

class ObjectParams : public DisplayObject {
public:
  ObjectParams(int apX, int apY, int pX, int pY, int width, int height,
               int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
               uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  ObjectParams(int apX, int apY, int pX, int pY, int width, int height,
               double v0X, double v0Y, double aX, double aY, int createdAt,
               int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
               uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  ObjectParams(int apX, int apY, int pX, int pY, int width, int height,
               double v, double a, double dir, int createdAt,
               int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
               uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);

  ObjectParams();

  void Draw(sf::RenderWindow &window) override;

  friend class ObjectFactory;
};

#endif // CONSTRUCT_PARAMS_HPP