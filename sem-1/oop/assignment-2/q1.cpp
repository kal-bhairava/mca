#include<iostream>
#include<string>

using namespace std;

class Student{
	string name; int roll_no;
	public : 
	Student(){
		name = "Roshan Singh";
		roll_no = 123;
		
		cout << "Name : " << name << endl;
		cout << "Roll NO : "<< roll_no;
	}
};

int main(){
	Student s;
}
