#ifndef SFML__ELLIPSE_SHAPE__EXTENSION_
#define SFML__ELLIPSE_SHAPE__EXTENSION_

#include <SFML/Graphics.hpp>
#include <cmath>

namespace sf {

class EllipseShape : public sf::Shape {
public:
  explicit EllipseShape(const sf::Vector2f &radius = sf::Vector2f(0, 0))
      : m_radius(radius) {
    update();
  }

  inline void setRadius(const sf::Vector2f &radius) {
    m_radius = radius;
    update();
  }

  inline const sf::Vector2f &getRadius() const { return m_radius; }

  virtual inline size_t getPointCount() const { return 30; }

  virtual inline sf::Vector2f getPoint(size_t index) const {
    static const float pi = 3.141592654f;
    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;
    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
  }

private:
  sf::Vector2f m_radius;
};

} // namespace sf

#endif // SFML__ELLIPSE_SHAPE__EXTENSION_