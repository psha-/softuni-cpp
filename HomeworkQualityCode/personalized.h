#ifndef PERSONALIZED_H
#define PERSONALIZED_H

#include <string>

// Something that has a name
class Personalized
{
public:
    Personalized(std::string name);

    inline std::string getName() const
    {
        return m_Name;
    }

    inline void setName(std::string name)
    {
        m_Name = name;
    }

protected:
    std::string m_Name;
};

#endif // PERSONALIZED_H
