#include "sequencecollection.h"
#include "fibonaccisequence.h"
#include "primesequence.h"

// This program prints Fibonacci and Prime sequences in multiple threads.

using namespace std;


int main()
{
    SequenceCollection* sequences = new SequenceCollection();
    sequences->addSequence(new FibonacciSequence());
    sequences->addSequence(new PrimeSequence());

    sequences->printSequencesSimultaneously();

    return 0;
}

