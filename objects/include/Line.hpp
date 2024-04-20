#ifndef LINE_HPP
#define LINE_HPP

#include "DisplayObject.hpp"

class Line : public DisplayObject {
public:
  Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, uint8_t r_fill,
       uint8_t g_fill, uint8_t b_fill);

  Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, double v0_x,
       double v0_y, double a_x, double a_y, int created_at, uint8_t r_fill,
       uint8_t g_fill, uint8_t b_fill);

  Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, double v, double a,
       double dir, int created_at, uint8_t r_fill, uint8_t g_fill,
       uint8_t b_fill);

  void Draw(sf::RenderWindow &window) override;
};

#endif