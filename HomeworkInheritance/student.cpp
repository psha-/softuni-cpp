#include "student.h"

SoftUni::Student::Student()
{

}

SoftUni::Student::Student(unsigned short id, std::string name, Course* currentCourse, unsigned short currentCoursePoints, float avgMark)
    :Member(id, name, currentCourse), m_currentCoursePoints(currentCoursePoints), m_avgMark(avgMark)
{
}
