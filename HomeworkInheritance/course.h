#ifndef COURSE_H
#define COURSE_H

#include <string>

namespace SoftUni {

class Course
{
public:
    Course();
    Course(std::string name);
    inline std::string getName() const
    {
        return m_name;
    }
    inline void setName(std::string name)
    {
        m_name = name;
    }

private:
    std::string m_name;
};

}

#endif // COURSE_H
