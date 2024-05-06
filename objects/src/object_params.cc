#include "object_params.h"
#include "circle.h"
#include "display_object.h"
#include "ellipse.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, int borderThickness, uint8_t rFill,
                           uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                           uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, width, height, borderThickness, rFill,
                    gFill, bFill, rStroke, gStroke, bStroke) {}

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, double v0X, double v0Y, double aX,
                           double aY, int createdAt, int borderThickness,
                           uint8_t rFill, uint8_t gFill, uint8_t bFill,
                           uint8_t rStroke, uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apX, pX, pY, width, height, v0X, v0Y, aX, aY,
                    createdAt, borderThickness, rFill, gFill, bFill, rStroke,
                    gStroke, bStroke) {}

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, double v, double a, double dir,
                           int createdAt, int borderThickness, uint8_t rFill,
                           uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                           uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apX, pX, pY, width, height, v, a, dir, createdAt,
                    borderThickness, rFill, gFill, bFill, rStroke, gStroke,
                    bStroke) {}

ObjectParams::ObjectParams(DisplayObject *o) : DisplayObject(*o) {}

ObjectParams::ObjectParams() {}

ObjectParams::Type ObjectParams::DefineType(DisplayObject *o) {
  auto r1 = dynamic_cast<Circle *>(o);
  if (r1 != nullptr) {
    return kCircle;
  }

  auto r2 = dynamic_cast<Ellipse *>(o);
  if (r2 != nullptr) {
    return kEllipse;
  }

  auto r3 = dynamic_cast<Line *>(o);
  if (r3 != nullptr) {
    return kLine;
  }

  auto r4 = dynamic_cast<Rectangle *>(o);
  if (r4 != nullptr) {
    return kRectangle;
  }

  auto r5 = dynamic_cast<Triangle *>(o);
  if (r5 != nullptr) {
    return kTriangle;
  }

  return kRectangle;
}

void ObjectParams::Draw(sf::RenderWindow &window) {}

std::string ObjectParams::TypeToString(Type t) {
  switch (t) {
  case kCircle:
    return "Circle";
  case kEllipse:
    return "Ellipse";
  case kLine:
    return "Line";
  case kTriangle:
    return "Triangle";
  default:
    return "Rectangle";
  }
}