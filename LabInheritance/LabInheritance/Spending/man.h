#ifndef MAN_H
#define MAN_H

#include "person.h"
#include "bankaccount.h"
#include "woman.h"

class Man : public Person
{
public:
    Man(BankAccount);
    friend class Woman;
};

#endif // MAN_H
