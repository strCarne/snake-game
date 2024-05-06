#include "menu_item.h"

#include <functional>

#include "display_object.h"
#include "menu.h"
#include "submenu_position.h"
#include "text.h"

MenuItem::MenuItem(std::function<void(EventType const &)> const &callback,
                   DisplayObject *object, Text *text, SubmenuPosition pos)
    : DisplayObject(*object), callback_(callback), object_(object), text_(text),
      menu_(new Menu()), active_(false), focused_(false), master_(nullptr),
      depend_on_master_(false), pos_(pos) {
  text_->Center(object_->x1_, object_->y1_, object_->x2_, object_->y2_);
}

MenuItem::MenuItem(std::function<void(EventType const &)> const &callback,
                   DisplayObject *object, Text *text, MenuItem **master,
                   SubmenuPosition pos)
    : DisplayObject(*object), callback_(callback), object_(object), text_(text),
      menu_(new Menu()), active_(false), focused_(false), master_(master),
      depend_on_master_(true), pos_(pos) {
  text_->Center(object_->x1_, object_->y1_, object_->x2_, object_->y2_);
}

bool MenuItem::IsChild(MenuItem *item) {
  if (this == item) {
    return true;
  }
  bool res = false;
  if (active_) {
    for (auto child = menu_->items_.begin();
         child != menu_->items_.end() && !res; ++child) {
      res = (*child)->IsChild(item);
    }
  }
  return res;
}

void MenuItem::Draw(sf::RenderWindow &window) {
  // draw item
  object_->Draw(window);

  // if focused draw selection
  if (focused_) {
    sf::RectangleShape selection(
        {static_cast<float>(object_->x2_ - object_->x1_),
         static_cast<float>(object_->y2_ - object_->y1_)});
    selection.setPosition(object_->x_ap_ + object_->x1_,
                          object_->y_ap_ + object_->y1_);
    selection.setFillColor(sf::Color::Transparent);
    selection.setOutlineThickness(kSelectThickness);
    selection.setOutlineColor(sf::Color(kRSelect, kGSelect, kBSelect));
    window.draw(selection);
  }

  text_->Draw(window);

  if (active_) {
    ArrangeMenu();
    menu_->Draw(window);
  }
}

bool MenuItem::focused() { return focused_; }
void MenuItem::focused(bool b) { focused_ = b; }

bool MenuItem::active() { return active_; }
void MenuItem::active(bool b) { active_ = b; }

void MenuItem::Add(MenuItem *item) { menu_->Add(item); }

void MenuItem::Remove(MenuItem *item) { menu_->Remove(item); }
void MenuItem::Remove(int index) { menu_->Remove(index); }

void MenuItem::ArrangeMenu() {
  int y_start = y1_;

  for (auto item : menu_->items_) {
    int w = item->x2_ - item->x1_;
    switch (pos_) {
    case kLeft:
      item->x2_ = x1_ - padding;
      item->x1_ = item->x2_ - w;
      break;
    case kRight:
      item->x1_ = x2_ + padding;
      item->x2_ = item->x1_ + w;
      break;
    }

    item->x1_client_ = item->x1_ + item->border_thickness_;
    item->x2_client_ = item->x2_ - item->border_thickness_;

    int h = item->y2_ - item->y1_;
    item->y1_ = y_start;
    item->y1_client_ = item->y1_ + item->border_thickness_;
    y_start += h;
    item->y2_ = y_start;
    item->y2_client_ = item->y2_ - item->border_thickness_;

    item->object_->x_ap_ = item->x_ap_;
    item->object_->y_ap_ = item->y_ap_;
    item->object_->x1_ = item->x1_;
    item->object_->y1_ = item->y1_;
    item->object_->x2_ = item->x2_;
    item->object_->y2_ = item->y2_;
    item->object_->x1_client_ = item->x1_client_;
    item->object_->y1_client_ = item->y1_client_;
    item->object_->x2_client_ = item->x2_client_;
    item->object_->y2_client_ = item->y2_client_;

    item->text_->Center(item->x1_, item->y1_, item->x2_, item->y2_);

    y_start += padding;
  }
}

void MenuItem::Update(EventType const &type) { callback_(type); }

MenuItem::~MenuItem() {
  delete object_;
  delete menu_;
  delete text_;
}