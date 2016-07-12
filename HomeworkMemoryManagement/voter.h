#ifndef VOTER_H
#define VOTER_H

#include "person.h"

namespace Voting {

// For now completely identical to person, but it helps the abstraction.
class Voter: public Person
{
public:
    Voter();
    Voter(std::string name, unsigned int age, Gender gender, std::string residence, Ethnos ethnos);
};

}

#endif // VOTER_H
