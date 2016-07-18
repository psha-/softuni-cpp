#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "surfaceable.h"
#include "lenghtable.h"

class Circle : public Shape, public Surfaceable, public Lenghtable
{
public:
    Circle();
};

#endif // CIRCLE_H
