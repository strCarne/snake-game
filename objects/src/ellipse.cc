#include "ellipse.h"

Ellipse::Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
                 int border_thickness, uint8_t r_fill, uint8_t g_fill,
                 uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                 uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius_a << 1, radius_b << 1,
                    border_thickness, r_fill, g_fill, b_fill, r_stroke,
                    g_stroke, b_stroke) {

  radius_a_ = radius_a;
  radius_b_ = radius_b;
}

Ellipse::Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
                 double v0_x, double v0_y, double a_x, double a_y,
                 int created_at, int border_thickness, uint8_t r_fill,
                 uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke,
                 uint8_t g_stroke, uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius_a << 1, radius_b << 1, v0_x, v0_y,
                    a_x, a_y, created_at, border_thickness, r_fill, g_fill,
                    b_fill, r_stroke, g_stroke, b_stroke) {
  radius_a_ = radius_a;
  radius_b_ = radius_b;
}

Ellipse::Ellipse(int x_ap, int y_ap, int x, int y, int radius_a, int radius_b,
                 double v, double a, double dir, int created_at,
                 int border_thickness, uint8_t r_fill, uint8_t g_fill,
                 uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                 uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, radius_a, radius_b, v, a, dir, created_at,
                    border_thickness, r_fill, g_fill, b_fill, r_stroke,
                    g_stroke, b_stroke) {
  radius_a_ = radius_a;
  radius_b_ = radius_b;
}

void Ellipse::Draw(sf::RenderWindow &window) {
  sf::EllipseShape primitive;
  primitive.setPosition({static_cast<float>(x_ap_ + x1_client_),
                         static_cast<float>(y_ap_ + y1_client_)});
  primitive.setRadius({static_cast<float>(radius_a_ - border_thickness_),
                       static_cast<float>(radius_b_ - border_thickness_)});
  primitive.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  primitive.setOutlineThickness(border_thickness_);
  primitive.setOutlineColor(sf::Color(r_stroke_, g_stroke_, b_stroke_));
  window.draw(primitive);
}