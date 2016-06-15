#include "member.h"

SoftUni::Member::Member(unsigned short int id, std::string name, Course* currentCourse)
    : m_id(id), m_name(name), m_currentCourse(currentCourse)
{
}

namespace SoftUni {

    std::ostream& operator<<(std::ostream& os, const Member& member)
    {
        os << "Id: " << member.m_id << std::endl;
        os << "Name: " << member.m_name << std::endl;
        os << "Current course: " << member.m_currentCourse;
        return os;
    }

}
