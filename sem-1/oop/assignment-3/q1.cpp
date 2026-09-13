/*
Create a class Student with private data members name and marks.
Write a friend function to access and display these private data members. 
*/

#include <iostream>
#include <string>

using namespace std;

class Student{
	private:
		string name;
		float marks;
	public:
		Student(string n, float m) : name(n), marks(m) {};
		
		friend void show(Student s);
};

void show(Student s) {
    cout << endl << "Name : " << s.name;
    cout << endl << "Marks : " << s.marks;
}

int main(){
	Student s = Student("Student", 100);
	show(s);
}

