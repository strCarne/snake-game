#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "DisplayObject.hpp"

class Rectangle : public DisplayObject {
public:
  Rectangle(int x_ap, int y_ap, int x, int y, int width, int height,
            int border_thickness, uint8_t r_fill, uint8_t g_fill,
            uint8_t b_fill, uint8_t r_stroke = 0, uint8_t g_stroke = 0,
            uint8_t b_stroke = 0);

  Rectangle(int x_ap, int y_ap, int x, int y, int width, int height,
            double v0_x, double v0_y, double a_x, double a_y, int created_at,
            int border_thickness, uint8_t r_fill, uint8_t g_fill,
            uint8_t b_fill, uint8_t r_stroke = 0, uint8_t g_stroke = 0,
            uint8_t b_stroke = 0);

  Rectangle(int x_ap, int y_ap, int x, int y, int width, int height, double v,
            double a, double dir, int created_at, int border_thickness,
            uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
            uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  void Draw(sf::RenderWindow &window) override;
};

#endif