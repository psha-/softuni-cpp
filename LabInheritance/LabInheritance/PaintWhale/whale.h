#ifndef WHALE_H
#define WHALE_H

#include "color.h"
#include "size.h"

class Whale
{
public:
    Whale(Size size, Color skinColor, float mass);
protected:
    Size m_Size;
    Color m_SkinColor;
    float m_Mass;
};

#endif // WHALE_H
