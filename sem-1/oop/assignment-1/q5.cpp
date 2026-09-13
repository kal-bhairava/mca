#include<iostream>
#include<string>
using namespace std;

class Student{
	string name, degree, hostel;
	int roll_no;
	float current_cgpa;
	
	public : 
	void add_details(){
		update_details();
		update_hostel();
		update_degree();
		update_cgpa();
	}
	
	void display_details(){
		cout << "Student deetails " << endl << "Name : " << name << endl;
		cout << "Roll No : " << roll_no << endl;
		cout << "CGPA :" << current_cgpa << endl;
		cout << "Hostel " << hostel << endl;
		cout << "Degree " << degree;
	}
	
	private : 
	
	void update_details(){
		cout << "Enter name : ";
		getline(cin, name);
		cout << "Enter roll no. :";
		cin >> roll_no;
	}
	
	void update_cgpa(){
		cout << "Enter Currect CGPA. :";
		cin >> current_cgpa;
	}
	
	void update_hostel(){
		cout << "Enter hostel : ";
		cin.ignore();
		getline(cin, hostel);
	}
	
	void update_degree(){
		cout << "Enter hostel : ";
		cin.ignore();
		getline(cin, hostel);
	}
	
};

int main(){
	Student s;
	s.add_details();
	s.display_details();
}
