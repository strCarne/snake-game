#include "menu2.h"

#include "menu_item2.h"
#include <algorithm>
#include <stack>
Menu2::~Menu2() = default;

void Menu2::Draw(sf::RenderWindow &window) {
  for (auto &item : items_) {
    item->Draw(window);
  }
}

void Menu2::Update(sf::RenderWindow &window, sf::Event &event) {
  for (auto &item : items_) {
    item->callback_(window, event);
    if (item->active_) {
      item->submenu_->Update(window, event);
    }
  }
}

void Menu2::Add(MenuItem2 *item) { items_.emplace_back(item); }

bool Menu2::Remove(MenuItem2 *item) {
  bool removed = false;
  for (auto i = 0UL; i < items_.size() && !removed; i++) {
    if (items_[i].get() == item) {
      items_.erase(items_.begin() + i);
      return true;
    } else if (items_[i].get()->active_) {
      removed = items_[i].get()->submenu_->Remove(item);
    }
  }
  return removed;
}

void Menu2::Remove(size_t index) {
  if (index > items_.size()) {
    return;
  }

  items_.erase(items_.begin() + index);
}

bool Menu2::ApplyToPath(MenuItem2 *target, ApplyFunc apply,
                        bool follow_active) {
  for (auto item : items_) {
    if (item.get() == target) {
      apply(target);
      return true;
    } else {
      if (!follow_active || follow_active && item->active_) {
        auto target_was_found =
            item->submenu_->ApplyToPath(target, apply, follow_active);
        if (target_was_found) {
          apply(item.get());
          return true;
        }
      }
    }
  }

  return false;
}

MenuItem2 *Menu2::Parent(MenuItem2 *target, bool follow_active) {
  auto has = [&target](Menu2 *menu) {
    auto found = std::find_if(
        menu->items_.begin(), menu->items_.end(),
        [&target](shared<MenuItem2> i) { return i.get() == target; });

    return found != menu->items_.end();
  };

  if (has(this)) {
    return nullptr;
  }

  MenuItem2 *parent = nullptr;
  std::stack<Menu2 *> stack;
  stack.push(this);
  while (!stack.empty()) {
    auto curr = stack.top();
    stack.pop();

    if (has(curr)) {
      return parent;
    }

    for (auto item : curr->items_) {
      if (item->active_) {
        parent = item.get();
        stack.push(parent->submenu_.get());
      }
    }
  }

  return nullptr;
}