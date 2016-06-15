#ifndef GUESTTEACHER_H
#define GUESTTEACHER_H

#include <iostream>
#include "teacher.h"

namespace SoftUni {

class GuestTeacher : public Teacher
{
public:
    GuestTeacher(unsigned short int id, std::string name, Course* currentCourse, float currentCourseSalary);
    friend std::ostream& operator<<(std::ostream& os, const GuestTeacher& guestTeacher);
private:
    float m_currentCourseSalary;
};

}
#endif // GUESTTEACHER_H
