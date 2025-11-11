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
    vector<Student*> students;  
    int currentStudents;      

public:
    
    Course();
    Course(const string& code, const string& name, int maxStudents);
    ~Course();

   
    bool addStudent(Student* s);  

  
    void displayCourseInfo() const;            
};













#endif
