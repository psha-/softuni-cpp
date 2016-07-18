#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "surfaceable.h"
#include "lenghtable.h"

class Rectangle : public Shape, public Surfaceable, public Lenghtable
{
public:
    Rectangle(double a, double b);

    inline virtual double CalculateLength() const
    {
        return 2*(m_a+m_b);
    }

    inline virtual double CalculateSurface() const
    {
        return m_a*m_b;
    }

private:
    double m_a;
    double m_b;
};

#endif // RECTANGLE_H
