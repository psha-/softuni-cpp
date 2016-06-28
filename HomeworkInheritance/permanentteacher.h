#ifndef PERMANENTTEACHER_H
#define PERMANENTTEACHER_H

#include "teacher.h"

namespace SoftUni {

class PermanentTeacher: public Teacher
{
public:
    PermanentTeacher();
    PermanentTeacher(unsigned short int id, std::string name, Course* currentCourse, float monthlySalary);
    inline float getMonthlySalary() const
    {
        return m_monthlySalary;
    }
    inline void setMonthlySalary(float monthlySalary)
    {
        m_monthlySalary = monthlySalary;
    }

private:
    float m_monthlySalary;
};

}


#endif // PERMANENTTEACHER_H
