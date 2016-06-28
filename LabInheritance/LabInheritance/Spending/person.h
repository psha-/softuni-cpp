#ifndef PERSON_H
#define PERSON_H

#include "bankaccount.h"

class Person
{
public:
    Person(BankAccount);
protected:
    BankAccount m_BankAccount;
};

#endif // PERSON_H
