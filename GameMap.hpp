#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include "DisplayObject.hpp"
#include <vector>
#include <memory>
#include <stdexcept>

class GameMap : public DisplayObject {
public:
  GameMap(int apX, int apY, int pX, int pY, int width, int height, 
    int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
    uint8_t rStroke = 0, uint8_t gStroke = 0, uint8_t bStroke = 0,
    int objCap = 32);

  void add(DisplayObject *object);
  std::unique_ptr<DisplayObject> remove(int index);

  void draw(sf::RenderWindow &w) override;

private:

  // Пул объектов, хранимый полем.
  std::vector<std::unique_ptr<DisplayObject>> objects;
};

#endif