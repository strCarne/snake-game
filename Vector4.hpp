#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace sf {

template <typename T>
class Vector4 {
public:
  Vector4(): Vector4(0, 0, 0, 0) {} 

  Vector4(T x1, T y1, T x2, T y2):  x1(x1), y1(y1), x2(x2), y2(y2) {}

  T x1, y1, x2, y2;
};

}

#endif