#include "GameField.hpp"

#include <stack>

GameField::GameField(int x_ap, int y_ap, int x, int y, int width, int height,
                     int border_thickness, uint8_t r_fill, uint8_t g_fill,
                     uint8_t b_fill, uint8_t r_stroke, uint8_t g_stroke,
                     uint8_t b_stroke, int pool_cap)
    : DisplayObject(x_ap, y_ap, x, y, width, height, border_thickness, r_fill,
                    g_fill, b_fill, r_stroke, g_stroke, b_stroke) {

  if (x2_client_ - x1_client_ <= 0 || y2_client_ - y1_client_ <= 0) {
    throw std::invalid_argument("GameField::GameField: no client part");
  }

  objects.reserve(pool_cap);
}

void GameField::Add(DisplayObject *object) { objects.push_back(object); }

DisplayObject *GameField::Remove(int index) {
  if (index < 0 || index >= objects.size()) {
    return nullptr;
  }

  DisplayObject *obj = objects[index];
  objects[index] = objects[objects.size() - 1];
  objects.resize(objects.size() - 1);
  return obj;
}

void GameField::Draw(sf::RenderWindow &window) {
  sf::RectangleShape primitive;
  primitive.setPosition({static_cast<float>(x_ap_ + x1_client_),
                         static_cast<float>(y_ap_ + y1_client_)});
  primitive.setSize({static_cast<float>(x2_client_ - x1_client_),
                     static_cast<float>(y2_client_ - y1_client_)});
  primitive.setOutlineThickness(border_thickness_);
  primitive.setFillColor(sf::Color(r_fill_, g_fill_, b_fill_));
  primitive.setOutlineColor(sf::Color(r_stroke_, g_stroke_, b_stroke_));

  window.draw(primitive);
  for (auto object : objects) {
    object->Draw(window);
  }
}

void GameField::Update(int timestamp) {
  std::stack<int> outer_objects_indices;
  for (int i = 0; i < objects.size(); i++) {
    objects[i]->Update(timestamp);
    if (!Contains(*objects[i])) {
      outer_objects_indices.push(i);
    }
  }

  while (!outer_objects_indices.empty()) {
    int i = outer_objects_indices.top();
    outer_objects_indices.pop();
    objects[i]->ResetMovement(timestamp);
  }
}

GameField::~GameField() {
  for (int i = 0; i < objects.size(); i++) {
    delete objects[i];
  }
}