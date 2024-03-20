#include "GameMap.hpp"

GameMap::GameMap(sf::Vector2<int> const &ap, sf::Vector2<int> const &p, 
  sf::Vector2<int> const &size, int borderThickness, 
  sf::Vector3<uint8_t> const &color, sf::Vector3<uint8_t> const &borderColor):
  DisplayObject(ap, p, size, borderThickness, color, borderColor, false) {

  if (xClient2 - xClient1 <= 0 || yClient2 - yClient1 <= 0) {
    throw std::invalid_argument("GameMap::GameMap: no client part");
  }

  primitive.setPosition({static_cast<float>(xClient1), 
    static_cast<float>(yClient1)});
  primitive.setSize({static_cast<float>(xClient2 -xClient1),
    static_cast<float>(yClient2 - yClient1)});
  primitive.setOutlineThickness(borderThickness);
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineColor(sf::Color(rB, gB, bB));

  objects.reserve(32);
}

void GameMap::push(DisplayObject *object) {
  objects.emplace_back(object);
}

void GameMap::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  for (auto const &object : objects) {
      object->draw(w);
  }
}