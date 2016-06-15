#include "student.h"

SoftUni::Student::Student(unsigned short id, std::string name, Course* currentCourse, unsigned short currentCoursePoints, float avgMark)
    :Member(id, name, currentCourse), m_currentCoursePoints(currentCoursePoints), m_avgMark(avgMark)
{
}

namespace SoftUni {
    std::ostream& operator<<(std::ostream& os, const Student& student)
    {
        os << static_cast<const Member&>(student) << std::endl;
        os << "Current course points: " << student.m_currentCoursePoints << std::endl;
        os << "Average mark: " << student.m_avgMark;
        return os;
    }
}
