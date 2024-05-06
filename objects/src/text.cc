#include "text.h"

Text::Text(std::string const &text, std::filesystem::path const &path_to_font,
           int font_size, int x_ap, int y_ap, int x, int y, int width,
           int height, int border_thickness, uint8_t r_fill, uint8_t g_fill,
           uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke, uint8_t b_stroke)
    : DisplayObject(x_ap, y_ap, x, y, width, height, border_thickness, r_fill,
                    g_fill, b_fill, r_stroke, g_stroke, b_stroke),
      text_(text), path_to_font_(path_to_font), font_size_(font_size) {}

Text::Text(std::string const &text, std::filesystem::path const &path_to_font,
           int font_size)
    : Text((text), (path_to_font), font_size, 0, 0, 0, 0, 0, 0, 2, 255, 255,
           255) {}

void Text::Center(int x1, int y1, int x2, int y2) {
  sf::Font font;
  font.loadFromFile(path_to_font_);
  auto bounds = sf::Text(text_, font, font_size_).getGlobalBounds();

  auto x_center_desired = x1 + ((x2 - x1) >> 1);
  auto y_center_desired = y1 + ((y2 - y1) >> 1);

  auto x_center_got = bounds.left + (bounds.width / 2);
  auto y_center_got = bounds.top + (bounds.height / 2);

  auto x_offset = x_center_desired - x_center_got;
  auto y_offset = y_center_desired - y_center_got;

  x1_ = bounds.left + x_offset;
  y1_ = bounds.top + y_offset;

  x2_ = x1_ + bounds.width;
  y2_ = y1_ + bounds.height;

  x1_client_ = bounds.left + x_offset;
  y1_client_ = bounds.top + y_offset;

  x2_client_ = x1_client_ + bounds.width;
  y2_client_ = y1_client_ + bounds.height;
}

void Text::Draw(sf::RenderWindow &window) {
  static sf::Font font;
  static bool font_initialized = false;
  if (!font_initialized) {
    font.loadFromFile(path_to_font_);
  }

  sf::Text text(text_, font, font_size_);
  text.setPosition(x1_, y1_);
  text.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  text.setOutlineColor(sf::Color::Black);
  text.setOutlineThickness(1);

  window.draw(text);
}

// Text *Text::Clone() { return new Text(text_, path_to_font_, font_size_); }
Text *Text::Clone() { return new Text(*this); }