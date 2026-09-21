/*
Create a base class College with a constructor that initializes the College
Name. Create a derived class Department with a constructor that initializes
the Department Name.
Create an object of the derived class and display both college and department
information to show the order of constructor execution.
*/

#include <iostream>
#include <string>

using namespace std;

class College {
protected:
    string collegeName;

public:
    College(string cName) {
        collegeName = cName;
        cout << "[Constructor] College class initialized. College: " << collegeName << endl;
    }

    ~College() {
        cout << "[Destructor] College class destroyed for: " << collegeName << endl;
    }
};

class Department : public College {
private:
    string departmentName;

public:
    Department(string cName, string dName) : College(cName) {
        departmentName = dName;
        cout << "[Constructor] Department class initialized. Department: " << departmentName << endl;
    }

    ~Department() {
        cout << "[Destructor] Department class destroyed for: " << departmentName << endl;
    }

    void displayInfo() const {
        cout << "\n--- Displaying Information ---\n";
        cout << "College Name    : " << collegeName << endl;
        cout << "Department Name : " << departmentName << endl;
    }
};

int main() {
    
    Department dept("Cllg - 1 ", "Cllg - 2");

    dept.displayInfo();

    return 0;
}
