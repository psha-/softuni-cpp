#include "course.h"

SoftUni::Course::Course(std::string name):m_name(name)
{
}

namespace SoftUni {
    std::ostream& operator<<(std::ostream& os, const Course& course)
    {
        os << course.m_name;
        return os;
    }
}
