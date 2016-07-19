#include "primesequence.h"
#include "primeelement.h"
#include <stdexcept>
#include <math.h>

PrimeSequence::PrimeSequence()
    :m_Prev(0), Sequence(new PrimeElement(0))
{
}

void PrimeSequence::calculateNext() throw(std::out_of_range)
{
    unsigned long long current = m_Prev+1;
    if(current < m_Prev) {
        throw std::out_of_range("Fibonacci number overflow");
    }
    while(true) {
        bool found = true;
        for(unsigned long long devider=sqrt(current); devider > 1; devider--) {
            if(current%devider == 0) {
                found = false;
                break;
            }
        }
        if(found) {
            setCurrent(new PrimeElement(current));
            m_Prev = current;
            return;
        }
        current++;
    }
}
