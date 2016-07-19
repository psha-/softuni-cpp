#include "fibonaccisequence.h"
#include "fibonaccielement.h"
#include <stdexcept>

FibonacciSequence::FibonacciSequence()
    :m_Prev1(0), m_Prev2(1), Sequence(new FibonacciElement(1))
{
}

void FibonacciSequence::calculateNext() throw(std::out_of_range)
{
    unsigned long long current = m_Prev1 + m_Prev2;
    if(current < m_Prev2) {
        throw std::out_of_range("Fibonacci number overflow");
    }
    m_Prev1 = m_Prev2;
    m_Prev2 = current;

    setCurrent(new FibonacciElement(current));
}
