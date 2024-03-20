#ifndef GAME_MAP_HPP
#define GAME_MAP_HPP

#include "DisplayObject.hpp"
#include <vector>
#include <memory>
#include <stdexcept>

class GameMap : public DisplayObject {
public:
  GameMap(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
    sf::Vector2<int> const &size, int borderThickness, 
    sf::Vector3<uint8_t> const &color, 
    sf::Vector3<uint8_t> const &borderColor = {0, 0, 0});

  void push(DisplayObject *object);

  void draw(sf::RenderWindow &w) override;

private:
  sf::RectangleShape primitive;

  // Пул объектов, хранимый полем.
  std::vector<std::unique_ptr<DisplayObject>> objects;
};

#endif