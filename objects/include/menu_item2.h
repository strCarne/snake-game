#pragma once

#include <functional>
#include <memory>
#include <string>

#include "display_object.h"
#include "drawable.h"
#include "text.h"
#include "updatable.h"

class Menu2;

class MenuItem2 : public Drawable, public Updatable {
private:
  template <typename T> using unique = std::unique_ptr<T>;

  using OwnedCallback = std::function<void(sf::RenderWindow &, sf::Event &)>;

public:
  using Callback =
      std::function<void(MenuItem2 *, sf::RenderWindow &, sf::Event &)>;

  enum Placement {
    kLeft,
    kRight,
  };

  MenuItem2(DisplayObject *base, Text *text,
            Callback callback = DefaultCallback, Placement placement = kRight);

  void Draw(sf::RenderWindow &window) override;
  void Update(sf::RenderWindow &window, sf::Event &event) override;

  std::string FullName();

  unique<DisplayObject> base_;
  unique<Menu2> submenu_;
  unique<Text> text_;

  OwnedCallback callback_;

  Placement placement_;

  bool focused_;
  bool active_;

  ~MenuItem2();

private:
  void ArrangeSubmenu();

  static void DefaultCallback(MenuItem2 *item, sf::RenderWindow &window,
                              sf::Event &event);
};