#include "votecollection.h"
#include "voter.h"
#include "vote.h"
#include "operators.h"
#include <limits>

using namespace std;
using namespace Voting;
using namespace Referendum;

namespace Referendum {
    const string COLLECTOR_PASSWORD = "12344321";

    Vote* inputVote()
    {
        Voter* voter = new Voter();

        cout << "Enter your data:" << endl;
        cin >> *voter;

        Option option;
        cout << "Option:" << endl;
        for(int i=0; i<Option::_COUNT; i++) {
            cout << (Option)i << endl;
        }
        cin >> option;

        cin.ignore (numeric_limits<streamsize>::max(), '\n');

        Vote* vote = new Vote(voter, option);
        return vote;
    }

    bool Login()
    {
        std::string password;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Password: ";
        getline(cin, password);
        if(password == COLLECTOR_PASSWORD) {
            return true;
        }
        return false;
    }

    enum Menu {
        VOTE = 'v',
        COLLECT_VOTES = 'c',
        HELP = '?',
        EXIT = 'x',
        // Collector menu:
        PERCENTAGE = 'p',
        TOTAL = 't',
        BY_AGE = 'a',
        BY_NAME = 'n',
        BY_ETHNOS = 'e',
        BY_RESIDENCE = 'r',
    };

    std::ostream& operator<<(std::ostream& os, const Menu& item)
    {
        os << (char)item;
        return os;
    }
}

int main()
{
    VoteCollection* Brexit = new VoteCollection();

    bool collectorMode = false;
    char choice;

    // It is really not that complex. Two switches for the two menus.
    while(true) {
        cout << "Welcome to main menu. Enter choice. " << HELP << " for help." << endl << "> ";
        cin >> choice;
        switch(choice) {

        case HELP:
            cout << VOTE << ": Vote now" << endl;
            cout << COLLECT_VOTES << ": Login to collector console" << endl;
            cout << EXIT << ": Exit" << endl;
            break;
        case VOTE:
            // This is important - voting
            Brexit->addVote(std::shared_ptr<Vote>(inputVote()));
            break;
        case EXIT:
            return 0;
        case COLLECT_VOTES:
        {
            if(!Login()) {
                cout << "Wrong password." << endl;
                break;
            }
            collectorMode = true;
            while(collectorMode) {
                cout << "Welcome to collector menu. Enter choice. " << HELP << " for help." << endl << "> ";
                cin >> choice;
                switch(choice) {

                case HELP:
                    cout << PERCENTAGE << ": Result in percents" << endl;
                    cout << TOTAL << ": Result in numbers" << endl;
                    cout << BY_AGE << ": Results by age" << endl;
                    cout << BY_NAME << ": Results by name" << endl;
                    cout << BY_ETHNOS << ": Results by ethnos" << endl;
                    cout << BY_RESIDENCE << ": Results by residence" << endl;
                    cout << HELP << ": Help" << endl;
                    cout << EXIT << ": Exit collector menu" << endl;
                    break;

                // These are important - collecting votes
                case PERCENTAGE:
                    cout << "Stay: " << Brexit->calcOptionPercentage(STAY) << "%, Leave: " << Brexit->calcOptionPercentage(LEAVE) << "%" << endl;
                    break;
                case TOTAL:
                    cout << "Stay: " << Brexit->getVotesCountByOption(STAY) << ", Leave: " << Brexit->getVotesCountByOption(LEAVE) << endl;
                    break;
                case BY_AGE:
                    unsigned int age;
                    cout << "Enter age: ";
                    cin >> age;
                    cout << age << "y - Stay: " << Brexit->getVotesCountByAgeAndOption(age, STAY) << ", Leave: " << Brexit->getVotesCountByAgeAndOption(age, LEAVE) << endl;
                    break;
                case BY_NAME:
                {
                    std::string name;
                    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Stay: " << Brexit->getVotesCountByNameAndOption(name, STAY) << ", Leave: " << Brexit->getVotesCountByNameAndOption(name, LEAVE) << endl;
                    break;
                }
                case BY_ETHNOS:
                    Ethnos ethnos;
                    cout << "Enter ethnos: " << endl;
                    for(int i=0; i<Ethnos::_COUNT; i++) {
                        cout << (Ethnos)i << endl;
                    }
                    cin >> ethnos;
                    cout << "Stay: " << Brexit->getVotesCountByEthnosAndOption(ethnos, STAY) << ", Leave: " << Brexit->getVotesCountByEthnosAndOption(ethnos, LEAVE) << endl;
                    break;
                case BY_RESIDENCE:
                {
                    std::string residence;
                    cout << "Enter residence: ";
                    cin >> residence;
                    cout << "Stay: " << Brexit->getVotesCountByResidenceAndOption(residence, STAY) << ", Leave: " << Brexit->getVotesCountByResidenceAndOption(residence, LEAVE) << endl;
                    break;
                }
                case EXIT:
                    collectorMode = false;
                    break;
                }
            }

            break;
        }
        }
    }
    return 0;
}

