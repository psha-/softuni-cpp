#include "permanentteacher.h"

SoftUni::PermanentTeacher::PermanentTeacher()
{
}

SoftUni::PermanentTeacher::PermanentTeacher(unsigned short int id, std::string name, Course* currentCourse, float monthlySalary)
    :Teacher(id, name, currentCourse), m_monthlySalary(monthlySalary)
{
}
