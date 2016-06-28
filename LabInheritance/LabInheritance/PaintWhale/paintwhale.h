#ifndef PAINTWHALE_H
#define PAINTWHALE_H
#include "paintobject.h"
#include "whale.h"
#include "color.h"

class PaintWhale: public PaintObject, public Whale
{
public:
    PaintWhale(Color color, Color backgroundColor, Size sheetSize, Size size, Color skinColor, float mass);
    float getScaleFactor() const;
};

#endif // PAINTWHALE_H
