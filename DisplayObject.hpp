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

  // Флаг, влияющий на отрисовку прямоугольника, ограничивающего объект. Если
  // значение истинно, то рамка отрисовывается, иначе - нет.
  bool drawBoundaries;

  // Метод для отрисовки, должен переопредялять объектом-наследником.
  virtual void draw(sf::RenderWindow &w) = 0;

  virtual ~DisplayObject() {}

protected:

  // Метод отрисовки границ фигуры.
  void renderBoundaries(sf::RenderWindow &w);

  // Обновляет графический примитив рамки в соотвествии с текущими координатами
  // объекта.
  void updateBoundaries();

  DisplayObject(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    sf::Vector2<int> const &size, int borderThickness, 
    sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0},
    bool drawBoundaries = false);

private:

  // Толщина рамки, ограничивающей объект.
  static const int boundaryThickness = 2;

  // Графический примитив для отображения рамки.
  sf::RectangleShape boundaries;
};

#endif