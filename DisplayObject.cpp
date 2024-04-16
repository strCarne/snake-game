#include "DisplayObject.hpp"
#include "Controller.hpp"
#include <cmath>

DisplayObject::DisplayObject(int apX, int apY, int pX, int pY, int width,
                             int height, int borderThickness, uint8_t rFill,
                             uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                             uint8_t gStroke, uint8_t bStroke) {

  xAP = apX;
  yAP = apY;

  x1 = pX;
  y1 = pY;
  x2 = x1 + width;
  y2 = y1 + height;

  xClient1 = x1 + borderThickness;
  yClient1 = y1 + borderThickness;
  xClient2 = x2 - borderThickness;
  yClient2 = y2 - borderThickness;

  s0X = x1;
  s0Y = y1;

  v0X = v0Y = aX = aY = 0.0;

  this->borderThickness = borderThickness;

  r = rFill;
  g = gFill;
  b = bFill;

  rB = rStroke;
  bB = gStroke;
  gB = bStroke;
}

DisplayObject::DisplayObject(int apX, int apY, int pX, int pY, int width,
                             int height, double v0X, double v0Y, double aX,
                             double aY, int createdAt, int borderThickness,
                             uint8_t rFill, uint8_t gFill, uint8_t bFill,
                             uint8_t rStroke, uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, width, height, borderThickness, rFill,
                    gFill, bFill, rStroke, gStroke, bStroke) {

  this->v0X = v0X;
  this->v0Y = v0Y;

  this->v = Controller::calcEuclide(v0X, v0Y);

  alpha = Controller::calcAngle(v0X, v0Y);

  this->aX = aX;
  this->aY = aY;

  a = Controller::calcEuclide(aX, aY);

  this->createdAt = createdAt;
}

DisplayObject::DisplayObject(int apX, int apY, int pX, int pY, int width,
                             int height, double v, double a, double dir,
                             int createdAt, int borderThickness, uint8_t rFill,
                             uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                             uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, height, width, v * std::cos(dir),
                    v * std::sin(dir), a * std::cos(dir), a * std::sin(dir),
                    createdAt, borderThickness, rFill, gFill, bFill, rStroke,
                    gStroke, bStroke) {}

void DisplayObject::update(int currentTime) {
  int dT = currentTime - createdAt;

  int dX = Controller::calcPosition(s0X, v0X, aX, dT) - x1;
  int dY = Controller::calcPosition(s0Y, v0Y, aY, dT) - y1;

  move(dX, dY);
}

bool DisplayObject::contains(int x, int y) {
  return (xClient1 <= x && x <= xClient2) && (yClient1 <= y && y <= yClient2);
}

bool DisplayObject::contains(DisplayObject const &obj) {
  return contains(obj.x1, obj.y1) || contains(obj.x2, obj.y1) ||
         contains(obj.x1, obj.y2) || contains(obj.x2, obj.y2);
}

bool DisplayObject::fullyContains(DisplayObject const &obj) {
  return contains(obj.x1, obj.y1) && contains(obj.x2, obj.y1) &&
         contains(obj.x1, obj.y2) && contains(obj.x2, obj.y2);
}

void DisplayObject::resetMovement(int timestamp) {
  int dX = s0X - x1;
  int dY = s0Y - y1;

  move(dX, dY);

  createdAt = timestamp;
}

void DisplayObject::move(int dX, int dY) {
  if (dX != 0) {
    x1 += dX;
    x2 += dX;

    xClient1 += dX;
    xClient2 += dX;
  }

  if (dY != 0) {
    y1 += dY;
    y2 += dY;

    yClient1 += dY;
    yClient2 += dY;
  }
}