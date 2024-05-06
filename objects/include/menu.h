#ifndef SNAKE_GAME__OBJECTS__MENU_H_
#define SNAKE_GAME__OBJECTS__MENU_H_

#include <functional>
#include <vector>

#include "display_object.h"

class MenuItem;

class Menu : public DisplayObject {
public:
  void Add(MenuItem *item);
  void Remove(MenuItem *item);
  void Remove(int index);

  std::pair<MenuItem *, bool> HandleClick(int x, int y,
                                          MenuItem *previous_selector);

  void Draw(sf::RenderWindow &window) override;

  MenuItem *Find(int x, int y,
                 std::function<void(MenuItem *item)> const &bottom_up_callback);

  Menu *GetParentMenu(MenuItem *item);

  ~Menu();

  friend class MenuItem;

private:
  std::vector<MenuItem *> items_;
};

#endif // SNAKE_GAME__OBJECTS__MENU_H_