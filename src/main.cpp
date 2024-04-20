#include "Game.hpp"

#define NAME "SnakeGG"
#define WIDTH 1000
#define HEIGHT 750
#define BORDER 10
#define FPS_LIMIT 60

int main() { Game(NAME, WIDTH, HEIGHT, BORDER, FPS_LIMIT).Run(); }