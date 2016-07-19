#ifndef PRIMEELEMENT_H
#define PRIMEELEMENT_H

#include "element.h"

class PrimeElement : public Element
{
public:
    PrimeElement(unsigned long long value)
        :m_Value(value)
    {
    }

    unsigned long long m_Value;

};

#endif // PRIMEELEMENT_H
