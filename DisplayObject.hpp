#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP

#include "Controller.hpp"
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

  // Скорость, угол направления.
  double v, alpha;

  // Начальная скорость (Проекции). Размерность - Пиксель/мс (мс - милисекунда)
  double v0X, v0Y;

  // Ускорение
  double a;

  // Ускорение (проекции).
  double aX, aY;

  // Начальное положение по x и y.
  int s0X, s0Y;

  // Время создания объекта в мс (милисекундах).
  int createdAt;

  // Толщина рамки.
  int borderThickness;

  // Цвет заливки.
  uint8_t r, g, b;

  // Цвет рамки.
  uint8_t rB, gB, bB;

  // Метод для отрисовки, должен переопредялять объектом-наследником.
  virtual void draw(sf::RenderWindow &w) = 0;

  // Обновляет положение объекта в соответствие со временем.
  virtual void update(int t);

  // Перемещает фигуру на указанное расстояние.
  virtual void move(int dX, int dY);

  // Проверяет, содержит ли объект точку.
  bool contains(int x, int y);

  // Проверят, содержит ли объект хотя бы часть другого объекта.
  bool contains(DisplayObject const &obj);

  // Проверяет, содержит ли объект другой полностью.
  bool fullyContains(DisplayObject const &obj);

  // Возвращает фигуру в начальное состояние.
  void resetMovement(int currentTime);

  virtual ~DisplayObject() {}

protected:
  DisplayObject(int apX, int apY, int pX, int pY, int width, int height,
                int borderThickness, uint8_t rFill, uint8_t gFill,
                uint8_t bFill, uint8_t rStroke = 0, uint8_t gStroke = 0,
                uint8_t bStroke = 0);

  DisplayObject(int apX, int apY, int pX, int pY, int width, int height,
                double v0X, double v0Y, double aX, double aY, int createdAt,
                int borderThickness, uint8_t rFill, uint8_t gFill,
                uint8_t bFill, uint8_t rStroke = 0, uint8_t gStroke = 0,
                uint8_t bStroke = 0);

  DisplayObject(int apX, int apY, int pX, int pY, int width, int height,
                double v, double a, double dir, int createdAt,
                int borderThickness, uint8_t rFill, uint8_t gFill,
                uint8_t bFill, uint8_t rStroke = 0, uint8_t gStroke = 0,
                uint8_t bStroke = 0);
};

#endif