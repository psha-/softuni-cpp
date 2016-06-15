#include "teacher.h"

SoftUni::Teacher::Teacher(unsigned short int id, std::string name, Course* currentCourse)
    :Member(id, name, currentCourse)
{
}

namespace SoftUni {
    std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
    {
        os << static_cast<const Member&>(teacher);
        return os;
    }
}
