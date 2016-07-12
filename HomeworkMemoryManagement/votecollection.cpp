#include "votecollection.h"
#include <iostream>

using namespace Voting;

VoteCollection::VoteCollection()
    :m_Votes(std::set<std::shared_ptr<Vote>>()),
      m_VotesByOption(VotesByOption(Option::_COUNT, std::set<std::shared_ptr<Vote>>())),
      m_VotesByAgeAndOption(std::map<unsigned int, VotesByOption>()),
      m_VotesByNameAndOption(std::map<std::string, VotesByOption>()),
      m_VotesByEthnosAndOption(std::map<Ethnos, VotesByOption>()),
      m_VotesByResidenceAndOption(std::map<std::string, VotesByOption>())
{
}

void VoteCollection::addVote(std::shared_ptr<Vote> vote)
{
    Option option = vote->getOption();
    unsigned int age = vote->getVoter()->getAge();
    std::string name = vote->getVoter()->getName();
    Ethnos ethnos = vote->getVoter()->getEthnos();
    std::string residence = vote->getVoter()->getResidence();

    if(m_VotesByAgeAndOption.find(age) == m_VotesByAgeAndOption.end()) {
        m_VotesByAgeAndOption.insert(std::pair<unsigned int, VotesByOption>(age, VotesByOption(Option::_COUNT, std::set<std::shared_ptr<Vote>>())));
    }
    if(m_VotesByNameAndOption.find(name) == m_VotesByNameAndOption.end()) {
        m_VotesByNameAndOption.insert(std::pair<std::string, VotesByOption>(name, VotesByOption(Option::_COUNT, std::set<std::shared_ptr<Vote>>())));
    }
    if(m_VotesByEthnosAndOption.find(ethnos) == m_VotesByEthnosAndOption.end()) {
        m_VotesByEthnosAndOption.insert(std::pair<Ethnos, VotesByOption>(ethnos, VotesByOption(Option::_COUNT, std::set<std::shared_ptr<Vote>>())));
    }
    if(m_VotesByResidenceAndOption.find(residence) == m_VotesByResidenceAndOption.end()) {
        m_VotesByResidenceAndOption.insert(std::pair<std::string, VotesByOption>(residence, VotesByOption(Option::_COUNT, std::set<std::shared_ptr<Vote>>())));
    }

    m_Votes.insert(vote);
    m_VotesByOption[option].insert(vote);
    m_VotesByAgeAndOption[age][option].insert(vote);
    m_VotesByNameAndOption[name][option].insert(vote);
    m_VotesByEthnosAndOption[ethnos][option].insert(vote);
    m_VotesByResidenceAndOption[residence][option].insert(vote);
}
