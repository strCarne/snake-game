#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "DisplayObject.hpp"

class Circle : public DisplayObject {
public:
  Circle(int x_ap, int y_ap, int x, int y, int radius, int border_thickness,
         uint8_t r_fill, uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
         uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Circle(int x_ap, int y_ap, int x, int y, int radius, double v0_x, double v0_y,
         double a_x, double a_y, int created_at, int border_thickness,
         uint8_t r_fill, uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
         uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Circle(int x_ap, int y_ap, int x, int y, int radius, double v, double a,
         double dir, int created_at, int border_thickness, uint8_t r_fill,
         uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
         uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  void Draw(sf::RenderWindow &window) override;

private:
  int radius_;
};

#endif // !CIRCLE_HPP