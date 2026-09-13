/*
Create a class Employee with a private data member salary.
Create two objects and use a friend function to compare their salaries and display the higher salary. 
*/

#include <iostream>
#include <strring>

using namespace std;

class Employee{
	private:
		float salary;
	public:
		string name;
		Employee(string n, float s){
			salary = s;
			name = n;
		}
		friend Employee compare(Employee, Employee);
};

Employee compare(Employee a, Employee b){
	if(a.salary > b.salary){
		return a;
	}
	return b;
}

int main(){
	Employee e1("Emp1", 1000), e2("Emp2", 2000);
	
	Employee higher = compare(e1, e2);
	
	cout << higher.name << " has higher salary";
}
