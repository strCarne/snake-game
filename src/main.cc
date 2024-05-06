#include "game.h"
#include "include/color_picker.h"
#include <SFML/Graphics.hpp>
#include <SFML/UI.hpp>
#include <iostream>
#include <utility>
#include <vector>

#define NAME "SnakeGG"
#define WIDTH 1300
#define HEIGHT 750
#define BORDER 8
#define FPS_LIMIT 60

int main() { Game(NAME, WIDTH, HEIGHT, BORDER, FPS_LIMIT).Run(); }
// int main() {
//   ColorPicker picker;
//   auto [r, g, b] = picker.pick();
//   std::cout << "Picked Color\n";
//   std::cout << "r -> " << static_cast<int>(r) << '\n';
//   std::cout << "g -> " << static_cast<int>(g) << '\n';
//   std::cout << "b -> " << static_cast<int>(b) << '\n';
// }