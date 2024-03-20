#include "Triangle.hpp"

Triangle::Triangle(sf::Vector2<int> const &ap, sf::Vector2<int> const &p1, 
  sf::Vector2<int> const &p2, sf::Vector2<int> const &p3, 
  int borderThickness, sf::Vector3<uint8_t> const &color, 
  sf::Vector3<uint8_t> const &borderColor, bool drawBoundaries): DisplayObject(
  ap, {}, {}, borderThickness, color, borderColor, drawBoundaries) {

  sf::Vector2<int> massCenter = {(p1.x + p2.x + p3.x) / 3, 
    (p1.y + p2.y + p3.y) / 3};

  sf::Vector4<int> l1(p1.x, p1.y, p2.x, p2.y);
  sf::Vector4<int> l2(p1.x, p1.y, p3.x, p3.y);
  sf::Vector4<int> l3(p2.x, p2.y, p3.x, p3.y);

  sf::Vector4<int> l1Inner = Controller::getClosestToApParallelLine(massCenter,
    l1, borderThickness);
  sf::Vector4<int> l2Inner = Controller::getClosestToApParallelLine(massCenter,
    l2, borderThickness);
  sf::Vector4<int> l3Inner = Controller::getClosestToApParallelLine(massCenter,
    l3, borderThickness);

  sf::Vector2<int> p1Inner = Controller::getLinesIntersection(l1Inner, l2Inner);
  sf::Vector2<int> p2Inner = Controller::getLinesIntersection(l1Inner, l3Inner);
  sf::Vector2<int> p3Inner = Controller::getLinesIntersection(l2Inner, l3Inner);

  primitive.setPointCount(3);
  primitive.setPoint(0, sf::Vector2f(p1Inner));
  primitive.setPoint(1, sf::Vector2f(p2Inner));
  primitive.setPoint(2, sf::Vector2f(p3Inner));
  primitive.setFillColor(sf::Color(r, g, b));
  primitive.setOutlineColor(sf::Color(rB, gB, bB));
  primitive.setOutlineThickness(borderThickness);

  sf::FloatRect bounds = primitive.getGlobalBounds();
  x1 = bounds.left;
  y1 = bounds.top;
  x2 = x1 + bounds.width;
  y2 = y1 + bounds.height;

  xClient1 = x1 + borderThickness;
  yClient1 = y1 + borderThickness;
  xClient2 = x2 - borderThickness;
  yClient2 = y2 - borderThickness;

  updateBoundaries();
}

void Triangle::draw(sf::RenderWindow &w) {
  w.draw(primitive);
  if (drawBoundaries) {
    DisplayObject::renderBoundaries(w);
  }
}