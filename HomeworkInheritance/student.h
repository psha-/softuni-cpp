#ifndef STUDENT_H
#define STUDENT_H

#include "member.h"

namespace SoftUni {

class Student : public Member {
public:
    Student();
    Student(unsigned short id, std::string name, Course* currentCourse, unsigned short currentCoursePoints, float avgMark);
    inline unsigned short getCurrentCoursePoints() const
    {
        return m_currentCoursePoints;
    }
    inline void setCurrentCoursePoints(unsigned short currentCoursePoints)
    {
        m_currentCoursePoints = currentCoursePoints;
    }
    inline float getAvgMark() const
    {
        return m_avgMark;
    }
    inline void setAvgMark(float avgMark)
    {
        m_avgMark = avgMark;
    }

private:
    unsigned short m_currentCoursePoints;
    float m_avgMark;
};

}


#endif // STUDENT_H
