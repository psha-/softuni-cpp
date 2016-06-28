#include <iostream>
#include "man.h"
#include "woman.h"
#include "bankaccount.h"

using namespace std;

int main()
{
    Man Pesho(BankAccount(1000));
    Woman Mary(Pesho);
    Mary.wasteMoney();
    return 0;
}

