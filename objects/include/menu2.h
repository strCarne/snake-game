#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

#include "drawable.h"
#include "updatable.h"

class MenuItem2;

class Menu2 : public Drawable, public Updatable {
private:
  template <typename T> using shared = std::shared_ptr<T>;
  template <typename T> using weak = std::weak_ptr<T>;
  template <typename T> using vec = std::vector<T>;

public:
  using ApplyFunc = std::function<void(MenuItem2 *)>;

  void Draw(sf::RenderWindow &window) override;
  void Update(sf::RenderWindow &window, sf::Event &event) override;

  void Add(MenuItem2 *item);
  bool Remove(MenuItem2 *item);
  void Remove(size_t index);

  bool ApplyToPath(MenuItem2 *target, ApplyFunc apply,
                   bool follow_active = true);

  MenuItem2 *Parent(MenuItem2 *target, bool follow_active = true);

  ~Menu2();

  vec<shared<MenuItem2>> items_;
};