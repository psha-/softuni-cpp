#ifndef PRIMEELEMENT_H
#define PRIMEELEMENT_H

#include <iostream>
#include <iomanip>
#include "element.h"

class PrimeElement : public Element
{
public:
    PrimeElement(unsigned long long value, double calculationTime);

    inline virtual void print()
    {
        std::cout << "Prime: " << m_Value << ", "<< std::fixed << m_CalculationTime << "ms" << std::endl;
    }

private:
    unsigned long long m_Value;
    double m_CalculationTime;

};

#endif // PRIMEELEMENT_H
