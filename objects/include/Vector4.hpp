#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace sf {

template <typename T> class Vector4 {
public:
  Vector4() : Vector4(0, 0, 0, 0) {}

  Vector4(T x1, T y1, T x2, T y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

  T x1_, y1_, x2_, y2_;
};

} // namespace sf

#endif