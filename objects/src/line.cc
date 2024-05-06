#include "line.h"

#include <cmath>

Line::Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, uint8_t r_fill,
           uint8_t g_fill, uint8_t b_fill)
    : DisplayObject(x_ap, y_ap, x1, y1, x2 - x1, y2 - y1, 0, r_fill, g_fill,
                    b_fill, 255, 255, 255) {}

Line::Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, double v0_x,
           double v0_y, double a_x, double a_y, int created_at, uint8_t r_fill,
           uint8_t g_fill, uint8_t b_fill)
    : Line(x_ap, y_ap, x1, y1, x2, y2, r_fill, g_fill, b_fill) {

  s0_x_ = x1_;
  s0_y_ = y1_;

  v0_x_ = v0_x;
  v0_y_ = v0_y;

  a_x_ = a_x;
  a_y_ = a_y;

  created_at_ = created_at;
}

Line::Line(int x_ap, int y_ap, int x1, int y1, int x2, int y2, double v,
           double a, double dir, int created_at, uint8_t r_fill, uint8_t g_fill,
           uint8_t b_fill)
    : Line(x_ap, y_ap, x1, y1, x2, y2, v * cos(dir), v * sin(dir), a * cos(dir),
           a * sin(dir), created_at, r_fill, g_fill, b_fill) {}

void Line::Draw(sf::RenderWindow &window) {
  sf::VertexArray primitive(sf::Lines, 2);
  primitive[0].position = {static_cast<float>(x_ap_ + x1_client_),
                           static_cast<float>(y_ap_ + y1_client_)};
  primitive[0].color = sf::Color(r_fill_, g_fill_, b_fill_);
  primitive[1].position = {static_cast<float>(x_ap_ + x2_client_),
                           static_cast<float>(y_ap_ + y2_client_)};
  primitive[1].color = sf::Color(r_fill_, g_fill_, b_fill_);
  window.draw(primitive);
}