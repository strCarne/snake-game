#include "Ellipse.hpp"

Ellipse::Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB,
                 int borderThickness, uint8_t rFill, uint8_t gFill,
                 uint8_t bFill, uint8_t rStroke, uint8_t gStroke,
                 uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, radiusA << 1, radiusB << 1,
                    borderThickness, rFill, gFill, bFill, rStroke, gStroke,
                    bStroke) {

  this->radiusA = radiusA;
  this->radiusB = radiusB;
}

Ellipse::Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB,
                 double v0X, double v0Y, double aX, double aY, int createdAt,
                 int borderThickness, uint8_t rFill, uint8_t gFill,
                 uint8_t bFill, uint8_t rStroke, uint8_t gStroke,
                 uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, radiusA << 1, radiusB << 1, v0X, v0Y, aX,
                    aY, createdAt, borderThickness, rFill, gFill, bFill,
                    rStroke, gStroke, bStroke) {
  this->radiusA = radiusA;
  this->radiusB = radiusB;
}

Ellipse::Ellipse(int apX, int apY, int pX, int pY, int radiusA, int radiusB,
                 double v, double a, double dir, int createdAt,
                 int borderThickness, uint8_t rFill, uint8_t gFill,
                 uint8_t bFill, uint8_t rStroke, uint8_t gStroke,
                 uint8_t bStroke)
    : Ellipse(apX, apY, pX, pY, radiusA, radiusB, v * cos(dir), v * sin(dir),
              a * cos(dir), a * sin(dir), createdAt, borderThickness, rFill,
              gFill, bFill, rStroke, gStroke, bStroke) {}

void Ellipse::draw(sf::RenderWindow &w) {
  sf::EllipseShape primitive;
  primitive.setPosition(
      {static_cast<float>(xClient1), static_cast<float>(yClient1)});
  primitive.setRadius({static_cast<float>(radiusA - borderThickness),
                       static_cast<float>(radiusB - borderThickness)});
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineThickness(borderThickness);
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  w.draw(primitive);
}