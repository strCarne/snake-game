#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Drawable {
public:
  // Метод для отрисовки, должен переопредялять объектом-наследником.
  virtual void Draw(sf::RenderWindow &window) = 0;

  virtual inline ~Drawable() {}
};