#include "fibonaccisequence.h"
#include "primesequence.h"
#include "sequencecollection.h"
#include "operators.h"
#include <iostream>
#include <memory>

// This program prints Fibonacci and Prime sequences in multiple threads.

using namespace std;

std::ostream& operator<<(std::ostream& os, const FibonacciElement& element)
{
    os << "Fibonacci: " << element.m_Value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const PrimeElement& element)
{
    os << "Prime: " << element.m_Value;
    return os;
}

std::ostream& operator<<(std::ostream& os, PrimeElement* element)
{
    os << "Prime: " << element->m_Value;
    return os;
}

//std::ostream& operator<<(std::ostream& os, std::shared_ptr<Element> element)
//{
//    os << "Prime: ";
////    os << "Prime: " << element->m_Value;
//    return os;
//}


int main()
{
    SequenceCollection* sequences = new SequenceCollection();
    sequences->addSequence(new FibonacciSequence());
    sequences->addSequence(new PrimeSequence());

    sequences->printSequencesSimultaneously();

    return 0;
}

