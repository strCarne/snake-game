#include "menu_item2.h"

#include "menu2.h"
#include <sstream>
MenuItem2::~MenuItem2() = default;

#include "display_object.h"
#include "text.h"

#include <__functional/bind.h>
#include <iostream>

MenuItem2::MenuItem2(DisplayObject *base, Text *text, Callback callback,
                     Placement placement)
    : base_(base), text_(text), submenu_(new Menu2()), focused_(false),
      active_(false), placement_(placement),
      callback_(std::bind(callback, this, std::placeholders::_1,
                          std::placeholders::_2)) {}

void MenuItem2::Draw(sf::RenderWindow &window) {
  base_->Draw(window);
  text_->Center(base_->x1_ + base_->x_ap_, base_->y1_ + base_->y_ap_,
                base_->x2_ + base_->x_ap_, base_->y2_ + base_->y_ap_);
  text_->Draw(window);
  if (active_) {
    ArrangeSubmenu();
    submenu_->Draw(window);
  }
  if (focused_) {
    sf::RectangleShape selection({static_cast<float>(base_->x2_ - base_->x1_),
                                  static_cast<float>(base_->y2_ - base_->y1_)});
    selection.setFillColor(sf::Color::Transparent);
    selection.setOutlineColor(sf::Color::Red);
    selection.setOutlineThickness(3);
    selection.setPosition(base_->x_ap_ + base_->x1_, base_->y_ap_ + base_->y1_);
    window.draw(selection);
  }
}

void MenuItem2::Update(sf::RenderWindow &window, sf::Event &event) {
  callback_(window, event);
}

void MenuItem2::ArrangeSubmenu() {
  static const auto padding = 10;

  int y_start = base_->y1_;

  for (auto item : submenu_->items_) {
    int w = item->base_->x2_ - item->base_->x1_;
    switch (placement_) {
    case kLeft:
      item->base_->x2_ = base_->x1_ - padding;
      item->base_->x1_ = item->base_->x2_ - w;
      break;
    case kRight:
      item->base_->x1_ = base_->x2_ + padding;
      item->base_->x2_ = item->base_->x1_ + w;
      break;
    }

    item->base_->x1_client_ = item->base_->x1_ + item->base_->border_thickness_;
    item->base_->x2_client_ = item->base_->x2_ - item->base_->border_thickness_;

    int h = item->base_->y2_ - item->base_->y1_;
    item->base_->y1_ = y_start;
    item->base_->y1_client_ = item->base_->y1_ + item->base_->border_thickness_;
    y_start += h;
    item->base_->y2_ = y_start;
    item->base_->y2_client_ = item->base_->y2_ - item->base_->border_thickness_;

    item->base_->x_ap_ = item->base_->x_ap_;
    item->base_->y_ap_ = item->base_->y_ap_;
    item->base_->x1_ = item->base_->x1_;
    item->base_->y1_ = item->base_->y1_;
    item->base_->x2_ = item->base_->x2_;
    item->base_->y2_ = item->base_->y2_;
    item->base_->x1_client_ = item->base_->x1_client_;
    item->base_->y1_client_ = item->base_->y1_client_;
    item->base_->x2_client_ = item->base_->x2_client_;
    item->base_->y2_client_ = item->base_->y2_client_;

    item->text_->Center(item->base_->x1_, item->base_->y1_, item->base_->x2_,
                        item->base_->y2_);

    y_start += padding;
  }
}

void MenuItem2::DefaultCallback(MenuItem2 *item, sf::RenderWindow &window,
                                sf::Event &event) {
  switch (event.type) {
  case sf::Event::MouseButtonReleased: {
    auto [x, y] = sf::Mouse::getPosition(window);
    if (item->base_->Contains(x, y)) {
      std::cout << "Clicked on item with id::" << item << '\n';
    }
  } break;
  }
}

std::string MenuItem2::FullName() {
  std::stringstream ss;
  ss << "<" << text_->text_ << "> (id::" << this << ")";
  return ss.str();
}