#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "course.h"

namespace SoftUni {

class Member {
public:
    Member();
    Member(unsigned short int id, std::string name, Course* currentCourse);
    inline unsigned short getId() const
    {
        return m_id;
    }
    inline void setId(unsigned short id)
    {
        m_id = id;
    }
    inline std::string getName() const
    {
        return m_name;
    }
    inline void setName(std::string name)
    {
        m_name = name;
    }
    inline Course* getCurrentCourse() const
    {
        return m_currentCourse;
    }
    inline void setCurrentCourse(Course* course)
    {
        m_currentCourse = course;
    }

protected:
    unsigned short m_id;
    std::string m_name;
    Course* m_currentCourse;
};

}

#endif // MEMBER_H
