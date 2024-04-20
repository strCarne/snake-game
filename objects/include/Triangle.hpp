#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Controller.hpp"
#include "DisplayObject.hpp"

class Triangle : public DisplayObject {
public:
  Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3, int y3,
           int border_thickness, uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
           uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3, int y3,
           double v0_x, double v0_y, double a_x, double a_y, int created_at,
           int border_thickness, uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
           uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3, int y3,
           double v, double a, double dir, int created_at, int border_thickness,
           uint8_t r_fill, uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke = 0,
           uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  void Draw(sf::RenderWindow &window) override;

  void Move(int d_x, int d_y) override;

private:
  int x1_p_, y1_p_, x2_p_, y2_p_, x3_p_, y3_p_;
};

#endif