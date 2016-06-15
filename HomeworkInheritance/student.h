#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "member.h"

namespace SoftUni {

class Student : public Member {
public:
    Student(unsigned short id, std::string name, Course* currentCourse, unsigned short currentCoursePoints, float avgMark);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
private:
    unsigned short int m_currentCoursePoints;
    float m_avgMark;
};

}
#endif // STUDENT_H
