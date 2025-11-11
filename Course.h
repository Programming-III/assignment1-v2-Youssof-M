#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
using namespace std;
//#write your code here
using namespace std;

class Student; 

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    int currentStudents;
    Student* students; // dynamically allocated array of students

public:
    // Constructors
    Course();
    Course(string courseCode, string courseName, int maxStudents, Student* initialStudents = nullptr, int currentStudents = 0);

    // Destructor
    ~Course();

    // Methods
    void addStudent(const Student& s);
    void displayCourseInfo() const;












#endif
