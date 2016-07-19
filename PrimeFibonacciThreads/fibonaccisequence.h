#ifndef FIBONACCISEQUENCE_H
#define FIBONACCISEQUENCE_H

#include "sequence.h"

class FibonacciSequence : public Sequence
{
public:
    FibonacciSequence();

    virtual void calculateNext() throw(std::out_of_range);

private:
    unsigned long long m_Prev1;
    unsigned long long m_Prev2;

};

#endif // FIBONACCISEQUENCE_H
