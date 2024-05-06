#ifndef SNAKE_GAME__OBJECTS__OBJECT_PARAMS_H_
#define SNAKE_GAME__OBJECTS__OBJECT_PARAMS_H_

#include "display_object.h"
#include "include/text.h"

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

  ObjectParams(DisplayObject *o);

  ObjectParams();

  void Draw(sf::RenderWindow &window) override;

  friend class ObjectFactory;

  Text *text;

  enum Type {
    kCircle,
    kEllipse,
    kLine,
    kRectangle,
    kTriangle,
  };

  static Type DefineType(DisplayObject *o);

  static std::string TypeToString(Type t);

  Type type;

  bool relyOnCoords = true;

  int d_x, d_y;
};

#endif // SNAKE_GAME__OBJECTS__OBJECT_PARAMS_H_