#ifndef PERSON_H
#define PERSON_H

#include "ethnos.h"
#include "gender.h"
#include <string>


class Person
{
public:
    Person();
    Person(std::string name, unsigned int age, Gender gender, std::string residence, Ethnos ethnos);

    inline void setName(std::string name)
    {
        m_Name = name;
    }

    inline std::string getName() const
    {
        return m_Name;
    }

    inline void setAge(unsigned int age)
    {
        m_Age = age;
    }

    inline unsigned int getAge() const
    {
        return m_Age;
    }

    inline void setGender(Gender gender)
    {
        m_Gender = gender;
    }

    inline Gender getGender() const
    {
        return m_Gender;
    }

    inline void setResidence(std::string residence)
    {
        m_Residence = residence;
    }

    inline std::string getResidence() const
    {
        return m_Residence;
    }

    inline void setEthnos(Ethnos ethnos)
    {
        m_Ethnos = ethnos;
    }

    inline Ethnos getEthnos() const
    {
        return m_Ethnos;
    }

protected:
    std::string m_Name;
    unsigned int m_Age;
    Gender m_Gender;
    std::string m_Residence;
    Ethnos m_Ethnos;

};

#endif // PERSON_H
