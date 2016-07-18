#include <iostream>

#include "calculator.h"
#include "rectangle.h"

using namespace std;

int main()
{
    Calculator* calc = new Calculator();
    Rectangle rect(3,5);
    cout << calc->CalculateLength(rect) << endl;
    cout << calc->CalculateSurface(rect) << endl;
    return 0;
}

