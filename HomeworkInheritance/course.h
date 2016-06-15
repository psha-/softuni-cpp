#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

namespace SoftUni {

class Course
{
public:
    Course(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const Course& course);
private:
    std::string m_name;
};

}
#endif // COURSE_H
