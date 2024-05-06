#ifndef SNAKE_GAME__OBJECTS__COLOR_PICKER_H_
#define SNAKE_GAME__OBJECTS__COLOR_PICKER_H_

#include <_types/_uint8_t.h>

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

class ColorPicker {
public:
  Color pick();

private:
  static Color HsvToRgb(double h, double s, double v);
};

#endif // SNAKE_GAME__OBJECTS__COLOR_PICKER_H_