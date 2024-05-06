#include "rectangle.h"

#include <cmath>

Rectangle::Rectangle(int x_ap, int y_ap, int x, int y, int width, int height,
                     int border_thickness, uint8_t r_fill, uint8_t g_fill,
                     uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                     uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, width, height, border_thickness, r_fill,
                    g_fill, b_fill, r_stroke, g_stroke, b_stroke) {}

Rectangle::Rectangle(int x_ap, int y_ap, int x, int y, int width, int height,
                     double v0_x, double v0_y, double a_x, double a_y,
                     int created_at, int border_thickness, uint8_t r_fill,
                     uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke,
                     uint8_t g_stroke, uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, width, height, v0_x, v0_y, a_x, a_y,
                    created_at, border_thickness, r_fill, g_fill, b_fill,
                    r_stroke, g_stroke, b_stroke) {}

Rectangle::Rectangle(int x_ap, int y_ap, int x, int y, int width, int height,
                     double v, double a, double dir, int created_at,
                     int border_thickness, uint8_t r_fill, uint8_t g_fill,
                     uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                     uint8_t b_stroke)
    : Rectangle(x_ap, y_ap, x, y, width, height, v * cos(dir), v * sin(dir),
                a * cos(dir), a * sin(dir), created_at, border_thickness,
                r_fill, g_fill, b_fill, r_stroke, g_stroke, b_stroke) {}

void Rectangle::Draw(sf::RenderWindow &window) {
  sf::RectangleShape primitive;
  primitive.setPosition(
      {static_cast<float>(x_ap_ +  x1_client_), static_cast<float>(y_ap_ + y1_client_)});
  primitive.setSize({static_cast<float>(x2_client_ - x1_client_),
                     static_cast<float>(y2_client_ - y1_client_)});
  primitive.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  primitive.setOutlineThickness(border_thickness_);
  primitive.setOutlineColor(sf::Color(r_stroke_, g_stroke_, b_stroke_));
  window.draw(primitive);
}