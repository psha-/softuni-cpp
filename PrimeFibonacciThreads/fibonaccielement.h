#ifndef FIBONACCIELEMENT_H
#define FIBONACCIELEMENT_H

#include "element.h"

class FibonacciElement : public Element
{
public:
    FibonacciElement(unsigned long long value)
        :m_Value(value)
    {
    }

    unsigned long long m_Value;

};

#endif // FIBONACCIELEMENT_H
