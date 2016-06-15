#include <iostream>
#include <unordered_map>
#include "student.h"
#include "permanentteacher.h"
#include "guestteacher.h"

using namespace std;
using namespace SoftUni;

namespace SoftUni {

    unordered_map<unsigned short, Student> students;
    unordered_map<unsigned short, Teacher> teachers;
    unordered_map<unsigned short, GuestTeacher> guestTeachers;

    template<typename T>
    void printMember(T collection)
    {
        unsigned short id;
        cout << "Id: ";
        cin >> id;
        auto found = collection.find(id);
        if( found == collection.end() ) {
            cout << "Not found." << endl;
        }
        else {
            cout << found->second << endl;
        }
    }

    bool AddStudent()
    {
        unsigned short id;
        string name;
        string courseName;
        unsigned short points;
        unsigned short avgMark;
        cout << "Add student." << endl;
        cout << "Id: ";
        cin >> id;
        if( students.find(id) != students.end() ) {
            return false;
        }
        cout << "Name: ";
        getline(cin, name);
        cout << "Current course name: ";
        getline(cin, courseName);
        cout << "Course points: ";
        cin >> points;
        cout << "Average evaluation mark: ";
        cin >> avgMark;

        students.insert(pair<unsigned short, Student>(id, Student(id, name, new Course(courseName), points, avgMark)));
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
    while(1) {
        cout << "Enter choice. " << HELP << " for help." << endl << "> ";
        int choice;
        cin >> choice;
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
            if( !AddStudent()) {
                cout << "Error adding student." << endl;
            }
            break;
        case ADD_TEACHER:
            break;
        case ADD_GUEST_TEACHER:
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

