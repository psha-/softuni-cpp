#ifndef GUESTTEACHER_H
#define GUESTTEACHER_H

#include "teacher.h"

namespace SoftUni {

class GuestTeacher : public Teacher
{
public:
    GuestTeacher();
    GuestTeacher(unsigned short int id, std::string name, Course* currentCourse, float currentCourseSalary);
    inline float getCurrentCourseSalary() const
    {
        return m_currentCourseSalary;
    }
    inline void setCurrentCourseSalary(float currentCourseSalary)
    {
        m_currentCourseSalary = currentCourseSalary;
    }

private:
    float m_currentCourseSalary;
};

}


#endif // GUESTTEACHER_H
