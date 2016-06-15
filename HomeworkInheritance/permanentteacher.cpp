#include "permanentteacher.h"

SoftUni::PermanentTeacher::PermanentTeacher(unsigned short int id, std::string name, Course* currentCourse, float monthlySalary)
    :Teacher(id, name, currentCourse), m_monthlySalary(monthlySalary)
{
}

namespace SoftUni {
    std::ostream& operator<<(std::ostream& os, const PermanentTeacher& permanentTeacher)
    {
        os << static_cast<const Teacher&>(permanentTeacher);
        os << "Monthly salary: " << permanentTeacher.m_monthlySalary;
        return os;
    }
}
