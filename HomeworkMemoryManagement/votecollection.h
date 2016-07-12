#ifndef VOTECOLLECTION_H
#define VOTECOLLECTION_H

#include "vote.h"
#include "option.h"
#include "votesbyoption.h"
#include "ethnos.h"
#include <map>
#include <set>
#include <string>
#include <memory>

namespace Voting {

// Below is a very stupid implementation of vote collection and is purely to exercise the smart pointers concept.
// m_Votes is a pile of all votes implemented as set.
// The rest of the members keep references to m_Votes via smart pointers.
// Calculating votes is just counting the references in the various members.
// The benefit is that you can trace any vote to the origin with its voter data.

class VoteCollection
{
public:
    VoteCollection();

    void addVote(std::shared_ptr<Vote> vote);

    inline float calcOptionPercentage(Option option) const
    {
        if(m_Votes.size() == 0) {
            return 0;
        }
        return (float)m_VotesByOption[option].size() / m_Votes.size() * 100;
    }

    inline unsigned long getVotesCountByOption(Option option) const
    {
        return m_VotesByOption[option].size();
    }

    inline unsigned long getVotesCountByAgeAndOption(unsigned int age, Option option)
    {
        if(m_VotesByAgeAndOption.find(age) == m_VotesByAgeAndOption.end()) {
            return 0;
        }
        return m_VotesByAgeAndOption[age][option].size();
    }

    inline unsigned long getVotesCountByNameAndOption(std::string name, Option option)
    {
        if(m_VotesByNameAndOption.find(name) == m_VotesByNameAndOption.end()) {
            return 0;
        }
        return m_VotesByNameAndOption[name][option].size();
    }

    inline unsigned long getVotesCountByEthnosAndOption(Ethnos ethnos, Option option)
    {
        if(m_VotesByEthnosAndOption.find(ethnos) == m_VotesByEthnosAndOption.end()) {
            return 0;
        }
        return m_VotesByEthnosAndOption[ethnos][option].size();
    }

    inline unsigned long getVotesCountByResidenceAndOption(std::string residence, Option option)
    {
        if(m_VotesByResidenceAndOption.find(residence) == m_VotesByResidenceAndOption.end()) {
            return 0;
        }
        return m_VotesByResidenceAndOption[residence][option].size();
    }

private:
    std::set<std::shared_ptr<Vote>> m_Votes;
    VotesByOption m_VotesByOption;
    std::map<unsigned int, VotesByOption> m_VotesByAgeAndOption;
    std::map<std::string, VotesByOption> m_VotesByNameAndOption;
    std::map<Ethnos, VotesByOption> m_VotesByEthnosAndOption;
    std::map<std::string, VotesByOption> m_VotesByResidenceAndOption;
};

}

#endif // VOTECOLLECTION_H
