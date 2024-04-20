#include "DisplayObject.hpp"
#include "Controller.hpp"
#include <cmath>

DisplayObject::DisplayObject(int x_ap, int y_ap, int x, int y, int width,
                             int height, int border_thickness, uint8_t r_fill,
                             uint8_t g_fill, uint8_t b_fill, uint8_t r_stroke,
                             uint8_t g_stroke, uint8_t b_stroke)
    : x_ap_(x_ap), y_ap_(y_ap), x1_(x), y1_(y), x2_(x + width), y2_(y + height),
      x1_client_(x + border_thickness), y1_client_(y + border_thickness),
      x2_client_(x2_ - border_thickness), y2_client_(y2_ - border_thickness),
      v_(0), alpha_(0), v0_x_(0), v0_y_(0), a_(0), a_x_(0), a_y_(0), s0_x_(x),
      s0_y_(y), created_at_(0), border_thickness_(border_thickness),
      r_fill_(r_fill), g_fill_(g_fill), b_fill_(b_fill), r_stroke_(r_stroke),
      g_stroke_(g_stroke), b_stroke_(b_stroke) {}

DisplayObject::DisplayObject(int x_ap, int y_ap, int x, int y, int width,
                             int height, double v0_x, double v0_y, double a_x,
                             double a_y, int created_at, int border_thickness,
                             uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
                             uint8_t r_stroke, uint8_t g_stroke,
                             uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, width, height, border_thickness, r_fill,
                    g_fill, b_fill, r_stroke, g_stroke, b_stroke) {

  v0_x_ = v0_x;
  v0_y_ = v0_y;

  v_ = Controller::CalcEuclideanDistance(v0_x, v0_y);
  alpha_ = Controller::CalcAngle(v0_x, v0_y);

  a_x_ = a_x;
  a_y_ = a_y;

  a_ = Controller::CalcEuclideanDistance(a_x, a_y);

  created_at_ = created_at;
}

DisplayObject::DisplayObject(int x_ap, int y_ap, int x, int y, int width,
                             int height, double v, double a, double dir,
                             int created_at, int border_thickness,
                             uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
                             uint8_t r_stroke, uint8_t g_stroke,
                             uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, height, width, border_thickness, r_fill,
                    g_fill, b_fill, r_stroke, g_stroke, b_stroke) {
  double dir_x = std::cos(dir);
  double dir_y = std::sin(dir);

  v0_x_ = v * dir_x;
  v0_y_ = v * dir_y;
  a_x_ = a * dir_x;
  a_y_ = a * dir_y;
  created_at_ = created_at;

  s0_x_ = x;
  s0_y_ = y;
}

DisplayObject::DisplayObject() {}

void DisplayObject::Update(int timestamp) {
  int d_t = timestamp - created_at_;

  int d_x = Controller::CalcPosition(s0_x_, v0_x_, a_x_, d_t) - x1_;
  int d_y = Controller::CalcPosition(s0_y_, v0_y_, a_y_, d_t) - y1_;

  Move(d_x, d_y);
}

bool DisplayObject::Contains(int x, int y) {
  return (x1_client_ <= x && x <= x2_client_) &&
         (y1_client_ <= y && y <= y2_client_);
}

bool DisplayObject::Contains(DisplayObject const &object, bool fully) {
  if (fully) {
    return Contains(object.x1_, object.y1_) &&
           Contains(object.x2_, object.y1_) &&
           Contains(object.x1_, object.y2_) && Contains(object.x2_, object.y2_);
  }
  return Contains(object.x1_, object.y1_) || Contains(object.x2_, object.y1_) ||
         Contains(object.x1_, object.y2_) || Contains(object.x2_, object.y2_);
}

void DisplayObject::ResetMovement(int timestamp) {
  int d_x = s0_x_ - x1_;
  int d_y = s0_y_ - y1_;

  Move(d_x, d_y);

  created_at_ = timestamp;
}

void DisplayObject::Move(int d_x, int d_y) {
  if (d_x != 0) {
    x1_ += d_x;
    x2_ += d_x;

    x1_client_ += d_x;
    x2_client_ += d_x;
  }

  if (d_y != 0) {
    y1_ += d_y;
    y2_ += d_y;

    y1_client_ += d_y;
    y2_client_ += d_y;
  }
}

int DisplayObject::x_ap() { return x_ap_; }
int DisplayObject::y_ap() { return y_ap_; }

int DisplayObject::x1() { return x1_; }
int DisplayObject::y1() { return y1_; }

int DisplayObject::x2() { return x2_; }
int DisplayObject::y2() { return y2_; }

int DisplayObject::x1_client() { return x1_client_; }
int DisplayObject::y1_client() { return y1_client_; }

int DisplayObject::x2_client() { return x2_client_; }
int DisplayObject::y2_client() { return y2_client_; }

double DisplayObject::v() { return v_; }
double DisplayObject::alpha() { return alpha_; }

double DisplayObject::a() { return a_; }

int DisplayObject::created_at() { return created_at_; }

int DisplayObject::border_thickness() { return border_thickness_; }

int DisplayObject::r_fill() { return r_fill_; }
int DisplayObject::g_fill() { return g_fill_; }
int DisplayObject::b_fill() { return b_fill_; }

int DisplayObject::r_stroke() { return r_stroke_; }
int DisplayObject::g_stroke() { return g_stroke_; }
int DisplayObject::b_stroke() { return b_stroke_; }