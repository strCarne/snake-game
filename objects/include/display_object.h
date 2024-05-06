#ifndef SNAKE_GAME__OBJECTS__DISPLAY_OBJECT_H_
#define SNAKE_GAME__OBJECTS__DISPLAY_OBJECT_H_

#include <SFML/Graphics.hpp>
#include <_types/_uint8_t.h>

#include "drawable.h"

class DisplayObject : public Drawable {
public:

  // Обновляет положение объекта в соответствие со временем.
  virtual void Update(int timestamp);

  // Перемещает фигуру на указанное расстояние.
  virtual void Move(int d_x, int d_y);

  // Проверяет, содержит ли объект точку.
  bool Contains(int x, int y);

  // Проверяет, содержит ли объект другой.
  bool Contains(DisplayObject const &object, bool fully = true);

  // Возвращает фигуру в начальное состояние.
  void ResetMovement(int currentTime);

  // AP (anchor point) - точка привязки.
  int x_ap_, y_ap_;

  // Координаты прямоугольника, ограничивающего отображаемый объект.
  int x1_, y1_;
  int x2_, y2_;

  // Координаты клиентской части (внутри рамки).
  int x1_client_, y1_client_;
  int x2_client_, y2_client_;

  // Скорость, угол направления.
  double v_, alpha_;

  // Начальная скорость (Проекции). Размерность - Пиксель/мс (мс - милисекунда)
  double v0_x_, v0_y_;

  // Ускорение
  double a_;

  // Ускорение (проекции).
  double a_x_, a_y_;

  // Начальное положение по x и y.
  int s0_x_, s0_y_;

  // Время создания объекта в мс (милисекундах).
  int created_at_;

  // Толщина рамки.
  int border_thickness_;

  // Цвет заливки.
  uint8_t r_fill_, g_fill_, b_fill_;

  // Цвет рамки.
  uint8_t r_stroke_, g_stroke_, b_stroke_;

  virtual ~DisplayObject() {}

protected:
  DisplayObject(int x_ap, int y_ap, int x, int y, int width, int height,
                int border_thickness, uint8_t r_fill, uint8_t g_fill,
                uint8_t b_fill, uint8_t r_stroke = 0, uint8_t g_stroke = 0,
                uint8_t b_stroke = 0);

  DisplayObject(int x_ap, int y_ap, int x, int y, int width, int height,
                double v0_x, double v0_y, double a_x, double a_y,
                int created_at, int border_thickness, uint8_t r_fill,
                uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
                uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  DisplayObject(int x_ap, int y_ap, int x, int y, int width, int height,
                double v, double a, double dir, int created_at,
                int border_thickness, uint8_t r_fill, uint8_t g_fill,
                uint8_t b_fill, uint8_t r_stroke = 0, uint8_t g_stroke = 0,
                uint8_t b_stroke = 0);

  DisplayObject(DisplayObject const &other);

  DisplayObject();
};

#endif // SNAKE_GAME__OBJECTS__DISPLAY_OBJECT_H_