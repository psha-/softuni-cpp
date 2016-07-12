#include "person.h"

Person::Person()
    :m_Name(), m_Age(), m_Gender(), m_Residence(), m_Ethnos()
{
}

Person::Person(std::string name, unsigned int age, Gender gender, std::string residence, Ethnos ethnos)
    : m_Name(name), m_Age(age), m_Gender(gender), m_Residence(residence), m_Ethnos(ethnos)
{
}
