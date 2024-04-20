#ifndef DISPLAY_OBJECT_FACTORY_HPP
#define DISPLAY_OBJECT_FACTORY_HPP

#include "DisplayObject.hpp"
#include "ObjectParams.hpp"

class ObjectFactory {
public:
  DisplayObject *rectangle(ObjectParams const &params);
  DisplayObject *circle(ObjectParams const &params);
  DisplayObject *ellipse(ObjectParams const &params);
  DisplayObject *line(ObjectParams const &params);
  DisplayObject *triangle(ObjectParams const &params);
};

#endif // DISPLAY_OBJECT_FACTORY_HPP