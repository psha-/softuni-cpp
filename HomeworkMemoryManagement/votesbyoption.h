#ifndef VOTESBYOPTION_H
#define VOTESBYOPTION_H

#include <vector>
#include <set>
#include <memory>
#include "vote.h"

namespace Voting {

// Saves lots of punctuation writing. Also hides 3 data structures.
typedef std::vector<std::set<std::shared_ptr<Vote>>> VotesByOption;

}

#endif // VOTESBYOPTION_H
