#include "GameMap.hpp"

GameMap::GameMap(int apX, int apY, int pX, int pY, int width, int height, 
  int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
  uint8_t rStroke, uint8_t gStroke, uint8_t bStroke, int objCap): 
  DisplayObject(apX, apY, pX, pY, width, height, borderThickness, rFill, gFill, 
  bFill, rStroke, gStroke, bStroke) {

  if (xClient2 - xClient1 <= 0 || yClient2 - yClient1 <= 0) {
    throw std::invalid_argument("GameMap::GameMap: no client part");
  }

  objects.reserve(objCap);
}

void GameMap::add(DisplayObject *object) {
  objects.emplace_back(object);
}

std::unique_ptr<DisplayObject> GameMap::remove(int index) {
    if (index < 0 || index >= objects.size()) {
        return nullptr;
    }
    std::unique_ptr<DisplayObject> obj = std::move(objects[index]);
    objects[index] = std::move(objects[objects.size() - 1]);
    objects.resize(objects.size() - 1);
    return obj;
}

void GameMap::draw(sf::RenderWindow &w) {
  sf::RectangleShape primitive;
  primitive.setPosition({static_cast<float>(xClient1), 
    static_cast<float>(yClient1)});
  primitive.setSize({static_cast<float>(xClient2 - xClient1),
    static_cast<float>(yClient2 - yClient1)});
  primitive.setOutlineThickness(borderThickness);
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineColor(sf::Color(rB, gB, bB));

  w.draw(primitive);
  for (auto const &object : objects) {
      object->draw(w);
  }
}