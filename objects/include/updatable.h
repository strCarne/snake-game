#pragma once

#include <SFML/Graphics.hpp>

class Updatable {
public:
  virtual void Update(sf::RenderWindow &window, sf::Event &event) = 0;

  virtual inline ~Updatable() {}
};