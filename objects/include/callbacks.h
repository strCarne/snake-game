#ifndef SNAKE_GAME__OBJECTS__CALLBACKS_H_
#define SNAKE_GAME__OBJECTS__CALLBACKS_H_

#include <SFML/Graphics.hpp>

#include "menu_item2.h"

class MenuItem2;

class Callbacks {
public:
  static inline void Button(MenuItem2 *item, sf::RenderWindow *window,
                            sf::Event &event) {
    switch (event.type) {
    case sf::Event::MouseButtonReleased: {
      auto [x, y] = sf::Mouse::getPosition(*window);
      if (item->base_->Contains(x, y)) {
        
      }
    } break;
    }
  }
};

#endif