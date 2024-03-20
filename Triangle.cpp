#include "Triangle.hpp"

Triangle::Triangle(int apX, int apY, int p1X, int p1Y, int p2X, int p2Y, int p3X, 
  int p3Y, int borderThickness, uint8_t rFill, uint8_t gFill, uint8_t bFill, 
  uint8_t rStroke, uint8_t gStroke, uint8_t bStroke): DisplayObject(apX, apY, 0, 
  0, 0, 0, borderThickness, rFill, gFill, bFill, rStroke, gStroke, bStroke) {

  sf::Vector2<int> massCenter = {(p1X + p2X + p3X) / 3, 
    (p1Y + p2Y + p3Y) / 3};

  sf::Vector4<int> l1(p1X, p1Y, p2X, p2Y);
  sf::Vector4<int> l2(p1X, p1Y, p3X, p3Y);
  sf::Vector4<int> l3(p2X, p2Y, p3X, p3Y);

  sf::Vector4<int> l1Inner = Controller::getClosestToApParallelLine(massCenter,
    l1, borderThickness);
  sf::Vector4<int> l2Inner = Controller::getClosestToApParallelLine(massCenter,
    l2, borderThickness);
  sf::Vector4<int> l3Inner = Controller::getClosestToApParallelLine(massCenter,
    l3, borderThickness);

  sf::Vector2<int> p1Inner = Controller::getLinesIntersection(l1Inner, l2Inner);
  sf::Vector2<int> p2Inner = Controller::getLinesIntersection(l1Inner, l3Inner);
  sf::Vector2<int> p3Inner = Controller::getLinesIntersection(l2Inner, l3Inner);

  this->p1X = p1Inner.x;
  this->p1Y = p1Inner.y;
  this->p2X = p2Inner.x;
  this->p2Y = p2Inner.y;
  this->p3X = p3Inner.x;
  this->p3Y = p3Inner.y;

  sf::ConvexShape primitive;
  primitive.setPointCount(3);
  primitive.setPoint(0, sf::Vector2f(p1Inner));
  primitive.setPoint(1, sf::Vector2f(p2Inner));
  primitive.setPoint(2, sf::Vector2f(p3Inner));

  sf::FloatRect bounds = primitive.getGlobalBounds();
  x1 = bounds.left;
  y1 = bounds.top;
  x2 = x1 + bounds.width;
  y2 = y1 + bounds.height;

  xClient1 = x1 + borderThickness;
  yClient1 = y1 + borderThickness;
  xClient2 = x2 - borderThickness;
  yClient2 = y2 - borderThickness;
}

void Triangle::draw(sf::RenderWindow &w) {
  sf::ConvexShape primitive;
  primitive.setPointCount(3);
  primitive.setPoint(0, sf::Vector2f(sf::Vector2i(p1X, p1Y)));
  primitive.setPoint(1, sf::Vector2f(sf::Vector2i(p2X, p2Y)));
  primitive.setPoint(2, sf::Vector2f(sf::Vector2i(p3X, p3Y)));
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  primitive.setOutlineThickness(borderThickness);
  w.draw(primitive);
}