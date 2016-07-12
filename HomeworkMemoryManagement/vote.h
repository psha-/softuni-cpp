#ifndef VOTE_H
#define VOTE_H

#include "voter.h"
#include "option.h"

namespace Voting {

class Vote
{
public:
    Vote();
    Vote(Voter* voter, Option option);

    inline void setVoter(Voter* voter)
    {
        m_Voter = voter;
    }

    inline Voter* getVoter() const
    {
        return m_Voter;
    }

    inline void setOption(Option option)
    {
        m_Option = option;
    }

    inline Option getOption() const
    {
        return m_Option;
    }

    ~Vote();

private:
    Voter* m_Voter;
    Option m_Option;
};

}
#endif // VOTE_H
