#ifndef SNAKE_GAME__OBJECTS__ELLIPSE_H_
#define SNAKE_GAME__OBJECTS__ELLIPSE_H_

#include "display_object.h"
#include "ellipse_shape.h"

class Ellipse : public DisplayObject {
public:
  Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
          int border_thickness, uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
          uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
          double v0_x, double v0_y, double a_x, double a_y, int created_at,
          int border_thickness, uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
          uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
          double v, double a, double dir, int created_at, int border_thickness,
          uint8_t r_fill, uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
          uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  void Draw(sf::RenderWindow &window) override;

private:
  int radius_a_, radius_b_;
};

#endif // SNAKE_GAME__OBJECTS__ELLIPSE_H_