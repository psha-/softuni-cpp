#ifndef WOMAN_H
#define WOMAN_H

#include "man.h"
#include "person.h"

class Man;

class Woman: public Person
{
public:
    Woman(Man &);
    void wasteMoney()
    {
        m_BankAccount.setBalance(0);
    }
};

#endif // WOMAN_H
