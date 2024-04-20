#include "ObjectFactory.hpp"

#include "Circle.hpp"
#include "DisplayObject.hpp"
#include "Ellipse.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

DisplayObject *ObjectFactory::rectangle(ObjectParams const &p) {
  int w = p.x2_ - p.x1_;
  int h = p.y2_ - p.y1_;
  return new Rectangle(p.x_ap_, p.y_ap_, p.x1_, p.y1_, w, h,
                       p.border_thickness_, p.r_fill_, p.g_fill_, p.b_fill_,
                       p.r_stroke_, p.g_stroke_, p.b_stroke_);
}

DisplayObject *ObjectFactory::circle(ObjectParams const &p) {
  int d = p.x2_ - p.x1_;
  int r = d >> 1;
  return new Circle(p.x_ap_, p.y_ap_, p.x1_, p.y1_, r, p.border_thickness_,
                    p.r_fill_, p.g_fill_, p.b_fill_, p.r_stroke_, p.g_stroke_,
                    p.b_stroke_);
}

DisplayObject *ObjectFactory::ellipse(ObjectParams const &p) {
  int d1 = p.x2_ - p.x1_;
  int d2 = p.y2_ - p.y1_;
  return new Ellipse(p.x_ap_, p.y_ap_, p.x1_, p.y1_, d1 >> 1, d2 >> 1,
                     p.border_thickness_, p.r_fill_, p.g_fill_, p.b_fill_,
                     p.r_stroke_, p.g_stroke_, p.b_stroke_);
}

DisplayObject *ObjectFactory::line(ObjectParams const &p) {
  return new Line(p.x_ap_, p.y_ap_, p.x1_, p.y1_, p.x2_, p.y2_, p.r_fill_,
                  p.g_fill_, p.b_fill_);
}

DisplayObject *ObjectFactory::triangle(ObjectParams const &p) {
  return new Triangle(p.x_ap_, p.y_ap_, p.x1_, p.y2_,
                      p.x1_ + ((p.x2_ - p.x1_) >> 1), p.y1_, p.x2_, p.y2_,
                      p.border_thickness_, p.r_fill_, p.g_fill_, p.b_fill_,
                      p.r_stroke_, p.g_stroke_, p.b_stroke_);
}