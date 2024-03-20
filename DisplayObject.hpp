#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP

#include <SFML/Graphics.hpp>

class DisplayObject {
public:
  // AP (anchor point) - точка привязки.
  int xAP, yAP;

  // Координаты прямоугольника, ограничивающего отображаемый объект.
  int x1, y1;
  int x2, y2;

  // Координаты клиентской части (внутри рамки).
  int xClient1, yClient1;
  int xClient2, yClient2;

  // Толщина рамки.
  int borderThickness;

  // Цвет заливки.
  uint8_t r, g, b;

  // Цвет рамки.
  uint8_t rB, gB, bB;

  // Метод для отрисовки, должен переопредялять объектом-наследником.
  virtual void draw(sf::RenderWindow &w) = 0;

  virtual ~DisplayObject() {}

protected:
  DisplayObject(int apX, int apY, int pX, int pY, int width, int height, 
    int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
    uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0);
};

#endif