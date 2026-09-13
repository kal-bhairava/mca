#include<iostream>
#include<string>

using namespace std;

class Student{
	string name;
	int roll_no;
	float cgpa;
	public:
		Student(){
			name = "No Name";
			roll_no = 0;
			cgpa = 0;
		}
		
		Student(string name, int roll_no){
			this->name = name;
			this->roll_no = roll_no;
			this->cgpa = 0;
		}
		
		Student(string name, int roll_no, float cgpa){
			this->name = name;
			this->roll_no = roll_no;
			this->cgpa = cgpa;
		}
		
		void display(){
			cout << endl << "Name : " << this->name << endl;
			cout << "Roll no : " << this->roll_no << endl;
			cout << "CGPA : " << this->cgpa << endl;
		}
};

int main(){
	Student s1 = Student(), s2 = Student("sample", 123), s3 = Student("Sample", 123, 9.9);
	s1.display();
	s2.display();
	s3.display();
}
