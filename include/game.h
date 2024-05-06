#ifndef SNAKE_GAME__GAME_H_
#define SNAKE_GAME__GAME_H_

#include <filesystem>
#include <string>

class Game {
public:
  Game(std::string const w_name, int w_width, int w_height,
       int w_border_thickness, int fps_limit);

  void Run() const;

public:
  std::string w_name_;
  int w_width_;
  int w_height_;
  int w_border_thickness_;
  int fps_limit_;

  static int const kAntialiasingLevel = 8;
  static inline std::filesystem::path kResourcesPath = "./resources";
  static inline std::filesystem::path kFontsPath = "fonts";
  static inline std::filesystem::path kDefaultFontPath = "big_blue_term.ttf";
};

#endif // SNAKE_GAME__GAME_H_