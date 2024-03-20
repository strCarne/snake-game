#include "DisplayObject.hpp"

DisplayObject::DisplayObject(int apX, int apY, int pX, int pY, int width, 
  int height, int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
  uint8_t rStroke, uint8_t gStroke, uint8_t bStroke) {
  
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

  this->borderThickness = borderThickness;

  r = rFill;
  g = gFill;
  b = bFill;

  rB = rStroke;
  bB = gStroke;
  gB = bStroke;

}
