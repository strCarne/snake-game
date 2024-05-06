#ifndef SNAKE_GAME__OBJECTS__TEXT_H_
#define SNAKE_GAME__OBJECTS__TEXT_H_

#include <_types/_uint8_t.h>
#include <filesystem>

#include "display_object.h"

class Text : public DisplayObject {
public:
  Text(std::string const &text, std::filesystem::path const &path_to_font,
       int font_size, int x_ap, int y_ap, int x, int y, int width, int height,
       int border_thickness, uint8_t r_fill, uint8_t g_fill, uint8_t b_fill,
       uint8_t r_stroke = 0, uint8_t g_stroke = 0, uint8_t b_stroke = 0);

  Text(std::string const &text, std::filesystem::path const &path_to_font,
       int font_size);

  void Center(int x1, int y1, int x2, int y2);

  void Draw(sf::RenderWindow &window) override;

  Text *Clone();

  std::string text_;

public:
  std::filesystem::path path_to_font_;
  int font_size_;
};

#endif // SNAKE_GAME__OBJECTS__TEXT_H_