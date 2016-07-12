#include "voter.h"

using namespace Voting;

Voter::Voter()
    :Person()
{
}

Voter::Voter(std::string name, unsigned int age, Gender gender, std::string residence, Ethnos ethnos)
    :Person(name, age, gender, residence, ethnos)
{
}
