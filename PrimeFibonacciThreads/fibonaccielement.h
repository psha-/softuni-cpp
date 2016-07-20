#ifndef FIBONACCIELEMENT_H
#define FIBONACCIELEMENT_H

#include <iostream>
#include <iomanip>
#include "element.h"

class FibonacciElement : public Element
{
public:
    FibonacciElement(unsigned long long value, double calculationTime);

    inline virtual void print()
    {
        std::cout << "Fibonacci: " << m_Value << ", " << std::fixed << m_CalculationTime << "ms" << std::endl;
    }

private:
    unsigned long long m_Value;
    double m_CalculationTime;

};

#endif // FIBONACCIELEMENT_H
