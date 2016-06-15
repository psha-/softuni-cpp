#ifndef PERMANENTTEACHER_H
#define PERMANENTTEACHER_H

#include <iostream>
#include "teacher.h"

namespace SoftUni {

class PermanentTeacher: public Teacher
{
public:
    PermanentTeacher(unsigned short int id, std::string name, Course* currentCourse, float monthlySalary);
    friend std::ostream& operator<<(std::ostream& os, const PermanentTeacher& permanentTeacher);
private:
    float m_monthlySalary;
};

}
#endif // PERMANENTTEACHER_H
