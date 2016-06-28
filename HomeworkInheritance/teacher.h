#ifndef TEACHER_H
#define TEACHER_H

#include "member.h"

namespace SoftUni {

class Teacher : public Member
{
public:
    Teacher();
    Teacher(unsigned short int id, std::string name, Course* currentCourse);
};

}


#endif // TEACHER_H
