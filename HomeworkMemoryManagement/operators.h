#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <string>
#include "option.h"
#include "ethnos.h"
#include "gender.h"
#include "person.h"
#include "voter.h"

// Operator overloads for input/output of the different custom types.
// Please do tell me a better place for these :(

using namespace Voting;

namespace Referendum {

inline std::ostream& operator<<(std::ostream& os, const Gender& gender)
{
    os << (char)gender;
    return os;
}

std::istream& operator>>(std::istream& is, Gender& gender)
{
    char g;
    is >> g;
    gender = (Gender)g;
    if(gender != F && gender != M) {
        throw std::invalid_argument("Please chose m or f");
    }
    return is;
}

std::istream& operator>>(std::istream& is, Ethnos& ethnos)
{
    int e;
    is >> e;
    ethnos = (Ethnos)e;
    if(ethnos < 0 || ethnos >= Ethnos::_COUNT) {
        throw std::invalid_argument("Please chose existing values");
    }
    return is;
}

std::istream& operator>>(std::istream& is, Option& option)
{
    int o;
    is >> o;
    option = (Option)o;
    if(option< 0 || option>= Option::_COUNT) {
        throw std::invalid_argument("Please chose existing values");
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Option& option)
{
    switch(option) {
    case STAY:
        os << "(" << (int)option<< ") " << "Stay";
        break;
    case LEAVE:
        os << "(" << (int)option<< ") " << "Leave";
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Ethnos& ethnos)
{
    switch(ethnos) {
    case EUROPEAN:
        os << "(" << (int)ethnos << ") " << "European";
        break;
    case AFRICAN:
        os << "(" << (int)ethnos<< ") " << "African";
        break;
    }

    return os;
}

std::istream& operator>>( std::istream& is, Person& person)
{
    {
        unsigned int age;
        std::cout << "Age: ";
        is >> age;
        is.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        person.setAge(age);
    }
    {
        std::string name;
        std::cout << "Name: ";
        std::getline(is, name);
        person.setName(name);
    }
    {
        Gender gender;
        std::cout << "Enter gender(" << M << "/" << F << "): ";
        is >> gender;
        is.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        person.setGender(gender);
    }
    {
        std::string city;
        std::cout << "City/village: ";
        getline(is, city);
        person.setResidence(city);
    }
    {
        Ethnos ethnos;
        std::cout << "Ethnos:" << std::endl;
        for(int i=0; i<Ethnos::_COUNT; i++) {
            std::cout << (Ethnos)i << std::endl;
        }
        is >> ethnos;
        person.setEthnos(ethnos);
    }

    return is;
}

std::istream& operator>>(std::istream& is, Voter& voter)
{
    is >> static_cast<Person&>(voter);
    return is;
}


}

#endif // OPERATORS_H
