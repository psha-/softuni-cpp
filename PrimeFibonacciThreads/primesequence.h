#ifndef PRIMESEQUENCE_H
#define PRIMESEQUENCE_H

#include "sequence.h"

class PrimeSequence : public Sequence
{
public:
    PrimeSequence();

    virtual void calculateNext() throw(std::out_of_range);

private:
    unsigned long long m_Prev;

};

#endif // PRIMESEQUENCE_H
