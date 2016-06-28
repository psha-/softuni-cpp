#include <iostream>
#include "paintwhale.h"
#include "size.h"

using namespace std;

int main()
{
    PaintWhale paintWhale(RED, GREEN, Size(480, 640), Size(200, 200), BLUE, 500.5);
    cout << paintWhale.getScaleFactor() << endl;
    return 0;
}

