#include "paintwhale.h"
#include <algorithm>

PaintWhale::PaintWhale(Color color, Color backgroundColor, Size sheetSize, Size size, Color skinColor, float mass)
    :PaintObject(color, backgroundColor, sheetSize), Whale(size, skinColor, mass)
{}

float PaintWhale::getScaleFactor() const
{
    return std::max((float)PaintObject::m_Size.x/Whale::m_Size.x, (float)PaintObject::m_Size.y/Whale::m_Size.y);
}
