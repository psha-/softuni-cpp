#ifndef POS_H
#define POS_H

#include <string>

namespace cashdesk {

// Point of sale
class POS
{
public:
    POS(std::string name, std::string BIC, std::string address);

    inline std::string getName() const
    {
        return m_Name;
    }

    inline std::string getBIC() const
    {
        return m_BIC;
    }

    inline std::string getAddress() const
    {
        return m_Address;
    }

private:
    std::string m_Name;
    std::string m_BIC;
    std::string m_Address;
};

}

#endif // POS_H
