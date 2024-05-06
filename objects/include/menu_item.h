#ifndef SNAKE_GAME__OBJECTS__MENU_ITEM_H_
#define SNAKE_GAME__OBJECTS__MENU_ITEM_H_

#include <_types/_uint8_t.h>
#include <functional>

#include "display_object.h"
#include "submenu_position.h"

class Menu;
class Text;

class MenuItem : public DisplayObject {
private:
  using EventType = sf::Event::EventType;

public:
  MenuItem(std::function<void(EventType const &)> const &callback,
           DisplayObject *object, Text *text, SubmenuPosition pos = kRight);
  MenuItem(std::function<void(EventType const &)> const &callback,
           DisplayObject *object, Text *text, MenuItem **master,
           SubmenuPosition pos = kRight);

  void Add(MenuItem *item);

  void Remove(MenuItem *item);
  void Remove(int index);

  bool IsChild(MenuItem *item);

  void Draw(sf::RenderWindow &window) override;

  bool focused();
  void focused(bool b);

  bool active();
  void active(bool b);

  void Update(EventType const &type);

  ~MenuItem();

  friend class Menu;

private:
  void ArrangeMenu();
  
  DisplayObject *object_;
  Menu *menu_;
  Text *text_;
  MenuItem **master_;
  std::function<void(EventType const &)> callback_;
  SubmenuPosition pos_;
  bool active_;
  bool focused_;
  bool depend_on_master_;

  static int const kSelectThickness = 3;
  static uint8_t const kRSelect = 255;
  static uint8_t const kGSelect = 0;
  static uint8_t const kBSelect = 0;

  static int const padding = 10;
};

#endif // SNAKE_GAME__OBJECTS__MENU_ITEM_H_