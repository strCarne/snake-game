#include "Triangle.hpp"

Triangle::Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3,
                   int y3, int border_thickness, uint8_t r_fill, uint8_t g_fill,
                   uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                   uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, 0, 0, 0, 0, border_thickness, r_fill, g_fill,
                    b_fill, r_stroke, g_stroke, b_stroke) {

  sf::Vector2<int> mass_center = {(x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3};

  sf::Vector4<int> l1(x1, y1, x2, y2);
  sf::Vector4<int> l2(x1, y1, x3, y3);
  sf::Vector4<int> l3(x2, y2, x3, y3);

  sf::Vector4<int> l1_inner =
      Controller::GetClosestToApParallelLine(mass_center, l1, border_thickness);
  sf::Vector4<int> l2_inner =
      Controller::GetClosestToApParallelLine(mass_center, l2, border_thickness);
  sf::Vector4<int> l3_inner =
      Controller::GetClosestToApParallelLine(mass_center, l3, border_thickness);

  sf::Vector2<int> p1_inner =
      Controller::GetLinesIntersection(l1_inner, l2_inner);
  sf::Vector2<int> p2_inner =
      Controller::GetLinesIntersection(l1_inner, l3_inner);
  sf::Vector2<int> p3_inner =
      Controller::GetLinesIntersection(l2_inner, l3_inner);

  x1_p_ = p1_inner.x;
  y1_p_ = p1_inner.y;
  x2_p_ = p2_inner.x;
  y2_p_ = p2_inner.y;
  x3_p_ = p3_inner.x;
  y3_p_ = p3_inner.y;

  sf::ConvexShape primitive;
  primitive.setPointCount(3);
  primitive.setPoint(0, sf::Vector2f(p1_inner));
  primitive.setPoint(1, sf::Vector2f(p2_inner));
  primitive.setPoint(2, sf::Vector2f(p3_inner));

  sf::FloatRect bounds = primitive.getGlobalBounds();
  x1_ = bounds.left;
  y1_ = bounds.top;
  x2_ = x1_ + bounds.width;
  y2_ = y1_ + bounds.height;

  x1_client_ = x1_ + border_thickness;
  y1_client_ = y1_ + border_thickness;
  x2_client_ = x2_ - border_thickness;
  y2_client_ = y2_ - border_thickness;
}

Triangle::Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3,
                   int y3, double v0_x, double v0_y, double a_x, double a_y,
                   int created_at, int border_thickness, uint8_t r_fill,
                   uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke,
                   uint8_t g_stroke, uint8_t b_stroke)
    : Triangle(x_ap, y_ap, x1, y1, x2, y2, x3, y3, border_thickness, r_fill,
               g_fill, b_fill, r_stroke, g_stroke, b_stroke) {

  s0_x_ = x1_;
  s0_y_ = y1_;

  v0_x_ = v0_x;
  v0_y_ = v0_y;

  a_x_ = a_x;
  a_y_ = a_y;

  created_at_ = created_at;
}

Triangle::Triangle(int x_ap, int y_ap, int x1, int y1, int x2, int y2, int x3,
                   int y3, double v, double a, double dir, int created_at,
                   int border_thickness, uint8_t r_fill, uint8_t g_fill,
                   uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                   uint8_t b_stroke)
    : Triangle(x_ap, y_ap, x1, y1, x2, y2, x3, y3, v * cos(dir), v * sin(dir),
               a * cos(dir), a * sin(dir), created_at, border_thickness, r_fill,
               g_fill, b_fill, r_stroke, g_stroke, b_stroke) {}

void Triangle::Draw(sf::RenderWindow &window) {
  sf::ConvexShape primitive;
  primitive.setPointCount(3);
  primitive.setPoint(0,
                     sf::Vector2f(sf::Vector2i(x_ap_ + x1_p_, y_ap_ + y1_p_)));
  primitive.setPoint(1,
                     sf::Vector2f(sf::Vector2i(x_ap_ + x2_p_, y_ap_ + y2_p_)));
  primitive.setPoint(2,
                     sf::Vector2f(sf::Vector2i(x_ap_ + x3_p_, y_ap_ + y3_p_)));
  primitive.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  primitive.setOutlineColor(sf::Color(r_stroke_, g_stroke_, b_stroke_));
  primitive.setOutlineThickness(border_thickness_);
  window.draw(primitive);
}

void Triangle::Move(int d_x, int d_y) {
  DisplayObject::Move(d_x, d_y);

  if (d_x != 0) {
    x1_p_ += d_x;
    x2_p_ += d_x;
    x3_p_ += d_x;
  }

  if (d_y != 0) {
    y1_p_ += d_y;
    y2_p_ += d_y;
    y3_p_ += d_y;
  }
}