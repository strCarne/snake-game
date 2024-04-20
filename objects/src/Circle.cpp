#include "Circle.hpp"
#include <cmath>

Circle::Circle(int x_ap, int y_ap, int x, int y, int radius,
               int border_thickness, uint8_t r_fill, uint8_t g_fill,
               uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
               uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius << 1, radius << 1,
                    border_thickness, r_fill, g_fill, b_fill, r_stroke,
                    g_stroke, b_stroke) {
  radius_ = radius;
}

Circle::Circle(int x_ap, int y_ap, int x, int y, int radius, double v0_x,
               double v0_y, double a_x, double a_y, int created_at,
               int border_thickness, uint8_t r_fill, uint8_t g_fill,
               uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
               uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius << 1, radius << 1, v0_x, v0_y, a_x,
                    a_y, created_at, border_thickness, r_fill, g_fill, b_fill,
                    r_stroke, g_stroke, b_stroke) {
  radius_ = radius;
}

Circle::Circle(int x_ap, int y_ap, int x, int y, int radius, double v, double a,
               double dir, int created_at, int border_thickness, uint8_t r_fill,
               uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke,
               uint8_t g_stroke, uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius << 1, radius << 1, v, a, dir,
                    created_at, border_thickness, r_fill, g_fill, b_fill,
                    r_stroke, g_stroke, b_stroke) {
  radius_ = radius;
}

void Circle::Draw(sf::RenderWindow &window) {
  sf::CircleShape primitive;
  primitive.setPosition({static_cast<float>(x_ap_ + x1_client_),
                         static_cast<float>(y_ap_ + y1_client_)});
  primitive.setRadius(radius_);
  primitive.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  primitive.setOutlineThickness(border_thickness_);
  primitive.setOutlineColor(sf::Color(r_stroke_, g_stroke_, b_stroke_));
  window.draw(primitive);
}