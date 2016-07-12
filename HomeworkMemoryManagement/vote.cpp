#include "vote.h"

using namespace Voting;

Vote::Vote()
    :m_Voter(), m_Option()
{
}

Vote::Vote(Voter* voter, Option option)
    :m_Voter(voter), m_Option(option)
{
}

Vote::~Vote()
{
    delete m_Voter;
}
