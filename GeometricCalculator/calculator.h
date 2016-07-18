#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "surfaceable.h"
#include "volumable.h"
#include "lenghtable.h"

class Calculator
{
public:
    Calculator();
    double CalculateSurface(const Surfaceable& shape);
    double CalculateLength(const Lenghtable& shape);
    double CalculateVolume(const Volumable& shape);

};

#endif // CALCULATOR_H
