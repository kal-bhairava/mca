#include<iostream>
#include<string>
using namespace std;

struct Student{
	string name, degree, hostel;
	int roll_no;
	float current_cgpa;
	
	void add_details(){
		cout << "Enter name : ";
		getline(cin, name);
		cout << "Enter roll no. :";
		cin >> roll_no;
		cin.ignore();
		cout << "Enter degree : ";
		getline(cin, degree);
		cout << "Enter hostel : ";
		getline(cin, hostel);
		cout << "Enter Currect CGPA. :";
		cin >> current_cgpa;
	}
	
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
		getline(cin, hostel);
	}
	
	void display_details(){
		cout << "Student deetails " << endl << "Name : " << name << endl;
		cout << "Roll No : " << roll_no << endl;
		cout << "CGPA :" << current_cgpa << endl;
		cout << "Hostel " << hostel << endl;
		cout << "Degree " << degree;
	}
};

int main(){
	Student s;
	s.add_details();
	s.display_details();
}
