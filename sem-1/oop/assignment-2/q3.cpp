#include<iostream>
#include<string>

using namespace std;

class Employee{
	string name;
	int id;
	float salary;
	
	public : 
		Employee(string name, int id, float salary){
			this->name = name;
			this->id = id;
			this->salary = salary;
		}
		
		void display(){
			cout << "Name : " << this->name << endl;
			cout << "ID : " << this->id << endl;
			cout << "Salary : " << this->salary;
		}
};

int main(){
	Employee e = Employee("Sample", 1234, 100000);
	e.display();
}
