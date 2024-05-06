#include "menu.h"

#include <algorithm>

#include "menu_item.h"

void Menu::Add(MenuItem *item) { items_.push_back(item); }

void Menu::Remove(MenuItem *item) {
  auto it = std::find_if(items_.begin(), items_.end(),
                         [item](MenuItem *curr) { return curr == item; });
  if (it != items_.end()) {
    delete *it;
    items_.erase(it);
  }
}

void Menu::Remove(int index) {
  if (0 <= index && index < items_.size()) {
    auto it = items_.begin() + index;
    delete *it;
    items_.erase(it);
  }
}

std::pair<MenuItem *, bool> Menu::HandleClick(int x, int y,
                                              MenuItem *previous_selector) {
  if (previous_selector != nullptr) {
    previous_selector->focused_ = false;
  }
  std::pair<MenuItem *, bool> res;
  res.first = Find(x, y, [](MenuItem *item) { item->active_ = true; });
  res.second = res.first != nullptr;
  bool in_same_menu =
      GetParentMenu(previous_selector) == GetParentMenu(res.first);
  if (in_same_menu && previous_selector != res.first) {
    previous_selector->focused_ = false;
    previous_selector->active_ = false;
  }
  if (previous_selector != nullptr &&
      !(previous_selector->IsChild(res.first) || in_same_menu)) {
    previous_selector->focused_ = false;
    previous_selector->active_ = false;
    bool reached = false;
    Find(previous_selector->x1_client_, previous_selector->y1_client_,
         [&res, this, &reached](MenuItem *item) {
           if (!reached) {
             reached =
                 this->GetParentMenu(item) == this->GetParentMenu(res.first);
             item->active_ = false;
           }
         });
  }
  if (res.second) {
    if (!res.first->depend_on_master_ || *res.first->master_ != nullptr) {
      res.first->focused_ = true;
      // res.first->callback_();
    } else {
      Find(res.first->x1_, res.first->y1_,
           [](MenuItem *item) { item->active_ = false; });
      res.first = nullptr;
    }
  }
  return res;
}

MenuItem *
Menu::Find(int x, int y,
           std::function<void(MenuItem *item)> const &bottom_up_callback) {
  for (auto item : items_) {
    if (item->object_->Contains(x, y)) {
      bottom_up_callback(item);
      return item;
    }
    if (item->active_) {
      auto res = (item)->menu_->Find(x, y, bottom_up_callback);
      if (res != nullptr) {
        bottom_up_callback(item);
        return res;
      }
    }
  }
  return nullptr;
}

void Menu::Draw(sf::RenderWindow &window) {
  for (auto item : items_) {
    item->Draw(window);
  }
}

Menu *Menu::GetParentMenu(MenuItem *item) {
  if (item == nullptr) {
    return nullptr;
  }
  for (auto i : items_) {
    if (i == item) {
      return this;
    }
    if (i->active_) {
      auto res = i->menu_->GetParentMenu(item);
      if (res != nullptr) {
        return res;
      }
    }
  }
  return nullptr;
}

Menu::~Menu() {
  for (auto item : items_) {
    delete item;
  }
}
