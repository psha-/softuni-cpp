#include "member.h"

SoftUni::Member::Member()
{
}

SoftUni::Member::Member(unsigned short int id, std::string name, Course* currentCourse)
    : m_id(id), m_name(name), m_currentCourse(currentCourse)
{
}


