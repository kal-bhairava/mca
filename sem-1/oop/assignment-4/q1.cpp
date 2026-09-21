/*
Create a C++ program to demonstrate Single Inheritance.
Create a base class Person with the following data members:
	Name
	Age
Create a derived class Student having:
	Roll Number
	Course
Implement member functions to accept and display the complete details of a
student using inheritance.
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void acceptPersonDetails() {
        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonDetails() const {
        cout << endl << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNumber;
    string course;

public:
    void acceptStudentDetails() {
        cout << "--- Enter Student Details ---\n";
        acceptPersonDetails();
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Course     : ";
        cin >> ws;
        getline(cin, course);
    }

    void displayStudentDetails() const {
        cout << "STUDENT RECORD";
        displayPersonDetails();
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Course      : " << course << endl;
    }
};

int main() {
    Student student1;

    student1.acceptStudentDetails();
    student1.displayStudentDetails();

    return 0;
}
