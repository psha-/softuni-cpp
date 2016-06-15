#include "guestteacher.h"

SoftUni::GuestTeacher::GuestTeacher(unsigned short int id, std::string name, Course* currentCourse, float currentCourseSalary)
    :Teacher(id, name, currentCourse), m_currentCourseSalary(currentCourseSalary)
{
}

namespace SoftUni {
    std::ostream& operator<<(std::ostream& os, const GuestTeacher& guestTeacher)
    {
        os << static_cast<const Teacher&>(guestTeacher) << std::endl;
        os << "Current course salary: " << guestTeacher.m_currentCourseSalary;
        return os;
    }
}
