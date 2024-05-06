#ifndef SNAKE_GAME__OBJECTS__OBJECT_FACTORY_H_
#define SNAKE_GAME__OBJECTS__OBJECT_FACTORY_H_

#include "display_object.h"
#include "object_params.h"

class ObjectFactory {
public:
  DisplayObject *rectangle(ObjectParams &params);
  DisplayObject *circle(ObjectParams &params);
  DisplayObject *ellipse(ObjectParams &params);
  DisplayObject *line(ObjectParams &params);
  DisplayObject *triangle(ObjectParams &params);

  DisplayObject *create(ObjectParams &params, bool move_after);
};

#endif // SNAKE_GAME__OBJECTS__OBJECT_FACTORY_H_