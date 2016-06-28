#ifndef PAINTOBJECT_H
#define PAINTOBJECT_H
#include "color.h"
#include "size.h"

class PaintObject
{
public:
    PaintObject(Color color, Color backgroundColor, Size size);
protected:
    Color m_Color;
    Color m_BackgroundColor;
    Size m_Size;
};

#endif // PAINTOBJECT_H
