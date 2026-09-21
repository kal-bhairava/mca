/*
Create a C++ program to demonstrate Multiple Inheritance.
Create two base classes:
Academic -> stores Marks
Sports -> stores Sports Score
Create a derived class Result that inherits from both classes and calculates the
total score and displays the result.
*/

#include <iostream>

using namespace std;


class Academic {
protected:
    float marks;

public:
    void acceptAcademic() {
        cout << "Enter Academic Marks: ";
        cin >> marks;
    }

    void displayAcademic() const {
        cout << "Academic Marks : " << marks << endl;
    }
};


class Sports {
protected:
    float sportsScore;

public:
    void acceptSports() {
        cout << "Enter Sports Score: ";
        cin >> sportsScore;
    }

    void displaySports() const {
        cout << "Sports Score   : " << sportsScore << endl;
    }
};


class Result : public Academic, public Sports {
private:
    float totalScore;

public:
    void acceptDetails() {
        acceptAcademic();
        acceptSports();
    }

    void displayResult() {
        totalScore = marks + sportsScore;
        
        cout << "\n--- Result Details ---\n";
        displayAcademic();
        displaySports();
        cout << "Total Score    : " << totalScore << endl;
    }
};

int main() {
    Result studentResult;

    cout << "Enter student details:\n";
    studentResult.acceptDetails();

    studentResult.displayResult();

    return 0;
}
