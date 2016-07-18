#include <iostream>
#include <math.h>
#include <thread>
#include <stdexcept>

// This program prints Fibonacci and Prime sequences in multiple threads.

using namespace std;

unsigned long long prevFibonacci1 = 0;
unsigned long long prevFibonacci2 = 1;

void printNextFibonacci()
{
    unsigned long long current = prevFibonacci1 + prevFibonacci2;
    if(current < prevFibonacci2) {
        throw out_of_range("Fibonacci number overflow");
    }
    prevFibonacci1 = prevFibonacci2;
    prevFibonacci2 = current;
    cout << current << endl;
}

unsigned long long prevPrime = 0;

void printNextPrime()
{
    unsigned long long current = prevPrime+1;
    while(true) {
        if(current < prevPrime) {
            throw out_of_range("Fibonacci number overflow");
        }
        for(unsigned long long devider=sqrt(prevPrime); devider < prevPrime; devider++) {
            if(prevPrime%devider == 0) {
                cout << current << endl;
            }
        }
        current++;
    }
}

int main()
{
    thread fibonacciThread(printNextFibonacci);
    thread primeThread(printNextPrime);
    return 0;
}

