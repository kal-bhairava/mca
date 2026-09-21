/*
Create a C++ program to demonstrate Multilevel Inheritance.
Create three classes:
Person -> stores Name
Employee -> stores Employee ID
Manager -> stores Department
Derive Employee from Person and Manager from Employee. Display all the
details of the manager.
*/

#include <iostream>
#include <string>

using namespace std;

// Base Class
class Person {
protected:
    string name;

public:
    void acceptPerson() {
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void displayPerson() {
        cout << "Name        : " << name << endl;
    }
};

class Employee : public Person {
protected:
    int empId;

public:
    void acceptEmployee() {
        acceptPerson();
        cout << "Enter Employee ID: ";
        cin >> empId;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID : " << empId << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    void acceptManager() {
        acceptEmployee();
        cout << "Enter Department: ";
        getline(cin, department);
    }

    void displayManager() {
        cout << "\n--- Manager Details ---\n";
        displayEmployee();
        cout << "Department  : " << department << endl;
    }
};

int main() {
    Manager mgr;

    cout << "Enter details for the manager:\n";
    mgr.acceptManager();

    mgr.displayManager();

    return 0;
}
