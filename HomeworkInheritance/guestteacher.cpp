#include "guestteacher.h"

SoftUni::GuestTeacher::GuestTeacher()
{
}

SoftUni::GuestTeacher::GuestTeacher(unsigned short int id, std::string name, Course* currentCourse, float currentCourseSalary)
    :Teacher(id, name, currentCourse), m_currentCourseSalary(currentCourseSalary)
{
}

