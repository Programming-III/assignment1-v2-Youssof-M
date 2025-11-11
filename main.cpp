#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
#include <string>

using namespace std;

Person::Person(string name, int id) {
    this->name = name;
    this->id = id;
}
void Person::display() {
    cout << "Name: " << name << ", ID: " << id << endl;
}

Student::Student(string name, int id,int yearLevel, string major):Person(name,id){
   this->yearLevel=yearLevel;
    this->major = major;
}
Student::Student() : Person("", 0) {
    this->yearLevel = 0;
    this->major = "";
}
void Student::display() {
    Person::display();
    cout << "Year Level: " << yearLevel << endl;
    cout<<"Major: " << major << endl;
}
Instructor::Instructor(string name, int id,string department, int experienceYears):Person(name,id){
    this->department=department;
    this->experienceYears=experienceYears;
}
void Instructor::display(){
    Person::display();
     cout << "department: " << department << endl;
     cout << "experience years: "<< experienceYears<<endl;
}

Course::Course() {
    this->courseCode = "XXX000";
    this->courseName = "NoName";
    this->maxStudents = 0;
    this->currentStudents = 0;
    this->students = nullptr;
}


Course::Course(string courseCode, string courseName, int maxStudents, Student* initialStudents, int currentStudents) {
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->maxStudents = maxStudents;

   
    this->students = new Student[maxStudents];

    
    this->currentStudents = (currentStudents < maxStudents) ? currentStudents : maxStudents;
    for (int i = 0; i < this->currentStudents; ++i) {
        this->students[i] = initialStudents[i];
    }
}


void Course::addStudent(const Student& s) {
    if (this->currentStudents < this->maxStudents) {
        this->students[this->currentStudents++] = s;
    } else {
        cout << "Cannot add student: course is full." << endl;
    }
}


void Course::displayCourseInfo() const {
    cout << "Course Info:" << endl;
    cout << "  " << courseCode << " - " << courseName << endl;
    cout << "Max students: " << maxStudents << endl;
    cout << "Currently enrolled: " << currentStudents << endl;
    cout << "Students:" << endl;

    for (int i = 0; i < currentStudents; ++i) {
        cout << "  Student " << (i + 1) << ":" << endl;
        students[i].display(); 
        cout << endl;
    }
}

// Destructor
Course::~Course() {
    delete[] this->students;
}
 
int main(){
    Student s1("alice",101,2, "Computer Science");
    s1.display();
    Instructor i1("Bob",105,"cs",3);
    i1.display();

   
    Student initialStudents[2] = {
        Student("Alice", 201, 2, "Mathematics"),
        Student("Charlie", 202, 1, "Physics")
    };

    Course c1("CS101","Intro to CS", 5, initialStudents, 2);

    cout << "instructor info:" << endl;
    i1.display();

    c1.displayCourseInfo();

    return 0;
 }
 }
