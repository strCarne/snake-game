#ifndef SNAKE_GAME__OBJECTS__CONTAINER_H_
#define SNAKE_GAME__OBJECTS__CONTAINER_H_


#include "display_object.h"
#include <vector>

class MenuItem;

// Container is responsible for the location of elements.
class Container : public DisplayObject {
protected:
  virtual void Arrange() = 0;

  
  // void Draw(sf::RenderWindow &window) = 0;
private:
  std::vector<MenuItem *> items_;
};

#endif