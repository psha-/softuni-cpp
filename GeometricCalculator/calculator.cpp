#include "calculator.h"

Calculator::Calculator()
{
}

double Calculator::CalculateSurface(const Surfaceable& object)
{
    return object.CalculateSurface();
}

double Calculator::CalculateLength(const Lenghtable& object)
{
    return object.CalculateLength();
}

double Calculator::CalculateVolume(const Volumable& object)
{
    return object.CalculateVolume();
}
