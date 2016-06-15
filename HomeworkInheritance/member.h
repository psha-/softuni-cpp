#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include "course.h"

namespace SoftUni {

class Member {
public:
    Member(unsigned short int id, std::string name, Course* currentCourse);
    friend std::ostream& operator<<(std::ostream& os, const Member& member);

protected:
    unsigned short int m_id;
    std::string m_name;
    Course* m_currentCourse;
};

}

#endif // MEMBER_H
