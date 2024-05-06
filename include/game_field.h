#ifndef SNAKE_GAME__GAME_FIELD_H_
#define SNAKE_GAME__GAME_FIELD_H_

#include <objects>

class GameField : public DisplayObject {
public:
  GameField(int x_ap, int y_ap, int x, int y, int width, int height,
            int border_thickness, uint8_t r_fill, uint8_t g_fill,
            uint8_t b_fill, uint8_t r_stroke = 0, uint8_t g_stroke = 0,
            uint8_t b_stroke = 0, int pool_cap = 32);

  void Add(DisplayObject *object);
  DisplayObject *Remove(int index);

  void Draw(sf::RenderWindow &window) override;

  void Update(int timestamp) override;

  ~GameField();

protected:
  // Пул объектов, хранимый полем.
  std::vector<DisplayObject *> objects;
};

#endif // SNAKE_GAME__GAME_FIELD_H_