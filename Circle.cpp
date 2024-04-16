#include "Circle.hpp"
#include <cmath>

Circle::Circle(int apX, int apY, int pX, int pY, int radius,
               int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
               uint8_t rStroke, uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, radius << 1, radius << 1, borderThickness,
                    rFill, gFill, bFill, rStroke, gStroke, bStroke) {
  this->radius = radius;
}

Circle::Circle(int apX, int apY, int pX, int pY, int radius, double v0X,
               double v0Y, double aX, double aY, int createdAt,
               int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill,
               uint8_t rStroke, uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, radius << 1, radius << 1, v0X, v0Y, aX,
                    aY, createdAt, borderThickness, rFill, gFill, bFill,
                    rStroke, gStroke, bStroke) {
  this->radius = radius;
}

Circle::Circle(int apX, int apY, int pX, int pY, int radius, double v, double a,
               double dir, int createdAt, int borderThickness, uint8_t rFill,
               uint8_t gFill, uint8_t bFill, uint8_t rStroke, uint8_t gStroke,
               uint8_t bStroke)
    : Circle(apX, apY, pX, pY, radius, v * cos(dir), v * sin(dir), a * cos(dir),
             a * sin(dir), createdAt, borderThickness, rFill, gFill, bFill,
             rStroke, gStroke, bStroke) {}

void Circle::draw(sf::RenderWindow &w) {
  sf::CircleShape primitive;
  primitive.setPosition(
      {static_cast<float>(xClient1), static_cast<float>(yClient1)});
  primitive.setRadius(radius);
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  w.draw(primitive);
}