/*
Create a class Student with a static data member to keep track of the number of objects created.
Create three objects and display the total number of objects. 
*/

#include <iostream>

using namespace std;

class Student{
	public:
		static int instances;
		
		Student(){
			instances++;
		}
};

int Student::instances; 

int main(){
	Student s1, s2, s3;
	cout << endl << "Total instances " <<  Student::instances;
	
	return 0;
}
