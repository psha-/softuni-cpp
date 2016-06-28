#include <iostream>
#include <ios>
#include <unordered_map>
#include <limits>
#include "student.h"
#include "permanentteacher.h"
#include "guestteacher.h"

using namespace std;
using namespace SoftUni;

namespace SoftUni {

    //TODO: Organize this better in external files

    std::ostream& operator<<(std::ostream& os, const SoftUni::Course& course)
    {
        os << course.getName();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SoftUni::Member& member)
    {
        os << "Id: " << member.getId() << std::endl;
        os << "Name: " << member.getName()<< std::endl;
        os << "Current course: " << *member.getCurrentCourse();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SoftUni::Teacher& teacher)
    {
        os << static_cast<const SoftUni::Member&>(teacher);
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SoftUni::PermanentTeacher& permanentTeacher)
    {
        os << static_cast<const SoftUni::Teacher&>(permanentTeacher) << std::endl;
        os << "Monthly salary: " << permanentTeacher.getMonthlySalary();
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const SoftUni::GuestTeacher& guestTeacher)
    {
        os << static_cast<const SoftUni::Teacher&>(guestTeacher) << std::endl;
        os << "Current course salary: " << guestTeacher.getCurrentCourseSalary();
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const SoftUni::Student& student)
    {
        os << static_cast<const SoftUni::Member&>(student) << std::endl;
        os << "Current course points: " << student.getCurrentCoursePoints() << std::endl;
        os << "Average mark: " << student.getAvgMark();
        return os;
    }

    std::istream& operator>>( istream& is, SoftUni::Course& course )
    {
        string name;
        cout << "Course name: ";
        getline(is, name);
        course.setName(name);
        return is;
    }

    std::istream& operator>>( istream& is, SoftUni::Member& member )
    {
        unsigned short id;
        string name;
        Course* currentCourse = new Course();

        cout << "Id: ";
        is >> id;
        //TODO fix adding characters after the number or characters instead of number
        is.ignore(/*std::numeric_limits<std::streamsize>::max(), EOF*/);
        is >> *currentCourse;
        cout << "Name: ";
        getline(is, name);

        member.setId(id);
        member.setName(name);
        member.setCurrentCourse(currentCourse);

        return is;
    }


    std::istream& operator>>( istream& is, SoftUni::Student& student )
    {
        cout << "Adding student." << endl;
        is >> static_cast<SoftUni::Member&>(student);
        unsigned short points;
        float avgMark;
        cout << "Current course points: ";
        is >> points;
        is.ignore();
        cout << "Average mark: ";
        is >> avgMark;
        is.ignore();

        student.setCurrentCoursePoints(points);
        student.setAvgMark(avgMark);

        return is;
    }

    std::istream& operator>>( istream& is, SoftUni::Teacher& teacher )
    {
        is >> static_cast<SoftUni::Member&>(teacher);
        return is;
    }

    std::istream& operator>>( istream& is, SoftUni::PermanentTeacher& permanentTeacher )
    {
        cout << "Adding teacher." << endl;
        is >> static_cast<SoftUni::Teacher&>(permanentTeacher);
        float salary;
        cout << "Monthly salary: ";
        is >> salary;
        is.ignore();
        permanentTeacher.setMonthlySalary(salary);

        return is;
    }

    std::istream& operator>>( istream& is, SoftUni::GuestTeacher& guestTeacher )
    {
        cout << "Adding guest teacher." << endl;
        is >> static_cast<SoftUni::Teacher&>(guestTeacher);
        float salary;
        cout << "Current course salary: ";
        is >> salary;
        is.ignore();
        guestTeacher.setCurrentCourseSalary(salary);

        return is;
    }


    unordered_map<unsigned short, Student*> students;
    unordered_map<unsigned short, PermanentTeacher*> teachers;
    unordered_map<unsigned short, GuestTeacher*> guestTeachers;

    template<typename T>
    void printMember(const T& collection)
    {
        unsigned short id;
        cout << "Id: ";
        cin >> id;
        auto found = collection.find(id);
        if( found == collection.end() ) {
            cout << "Not found." << endl;
        }
        else {
            cout << *found->second << endl;
        }
    }

    template<typename T>
    bool AddMember(unordered_map<unsigned short, T*>& collection)
    {
        T* member = new T();
        cin >> *member;
        if( collection.find(member->getId()) != collection.end() ) {
            return false;
        }
        collection.insert(pair<unsigned short, T*>(member->getId(), member));
        return true;
    }

    enum Menu {
        HELP,
        GET_STUDENT,
        GET_TEACHER,
        GET_GUEST_TEACHER,
        ADD_STUDENT,
        ADD_TEACHER,
        ADD_GUEST_TEACHER,
        EXIT,
    };

}



int main()
{
    while(true) {
        cout << "Enter choice. " << HELP << " for help." << endl << "> ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch(choice) {
        case HELP:
            cout << GET_STUDENT << ": Get data for student with ID" << endl;
            cout << GET_TEACHER << ": Get data for teacher with ID" << endl;
            cout << GET_GUEST_TEACHER << ": Get data for gest teacher with ID" << endl;
            cout << ADD_STUDENT << ": Add data for new student" << endl;
            cout << ADD_TEACHER << ": Add data for new teacher" << endl;
            cout << ADD_GUEST_TEACHER << ": Add data for new guest teacher" << endl;
            cout << EXIT << ": Exit" << endl;
            break;
        case GET_STUDENT:
            printMember(students);
            break;
        case GET_TEACHER:
            printMember(teachers);
            break;
        case GET_GUEST_TEACHER:
            printMember(guestTeachers);
            break;
        case ADD_STUDENT:
            if( !AddMember(students) ) {
                cout << "Student already exists." << endl;
            }
            break;
        case ADD_TEACHER:
            if( !AddMember(teachers) ) {
                cout << "Teacher already exists." << endl;
            }
            break;
        case ADD_GUEST_TEACHER:
            if( !AddMember(guestTeachers) ) {
                cout << "Guest teacher already exists." << endl;
            }
            break;
        case EXIT:
            return 0;
        default:
            cout << "Wrong choice." << endl;

        }
        cout << endl;
    }
    return 0;
}

