#include "ObjectParams.hpp"
#include "DisplayObject.hpp"

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, int borderThickness, uint8_t rFill,
                           uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                           uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apY, pX, pY, width, height, borderThickness, rFill,
                    gFill, bFill, rStroke, gStroke, bStroke) {}

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, double v0X, double v0Y, double aX,
                           double aY, int createdAt, int borderThickness,
                           uint8_t rFill, uint8_t gFill, uint8_t bFill,
                           uint8_t rStroke, uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apX, pX, pY, width, height, v0X, v0Y, aX, aY,
                    createdAt, borderThickness, rFill, gFill, bFill, rStroke,
                    gStroke, bStroke) {}

ObjectParams::ObjectParams(int apX, int apY, int pX, int pY, int width,
                           int height, double v, double a, double dir,
                           int createdAt, int borderThickness, uint8_t rFill,
                           uint8_t gFill, uint8_t bFill, uint8_t rStroke,
                           uint8_t gStroke, uint8_t bStroke)
    : DisplayObject(apX, apX, pX, pY, width, height, v, a, dir, createdAt,
                    borderThickness, rFill, gFill, bFill, rStroke, gStroke,
                    bStroke) {}

ObjectParams::ObjectParams() {}

void ObjectParams::Draw(sf::RenderWindow &window) {}