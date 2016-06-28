#include "teacher.h"

SoftUni::Teacher::Teacher()
{
}

SoftUni::Teacher::Teacher(unsigned short int id, std::string name, Course* currentCourse)
    :Member(id, name, currentCourse)
{
}

