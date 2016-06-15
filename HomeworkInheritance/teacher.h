#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include "member.h"

namespace SoftUni {

class Teacher : Member
{
public:
    Teacher(unsigned short int id, std::string name, Course* currentCourse);
    friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);
};

}
#endif // TEACHER_H
