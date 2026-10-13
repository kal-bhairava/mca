/*
 Create a class with overloaded result() functions to display marks in one subject, calculate the average of two subjects, and calculate the average of three subjects
*/

#include <iostream>
using namespace std;

class Exam{
	public:
		void result(double m){
			cout << endl << "Marks : " << m;
		}
		
		void result(double m1, double m2){
			cout << endl <<  "Average : " << (m1+m2) /2;
		}
		
		void result(double m1, double m2, double m3){
			cout << endl <<  "Average : " << (m1+m2+m3) /3;
		}
};

int main(){
	Exam e;
	e.result(99.0);
	e.result(99.0, 88.9);
	e.result(99.0, 99.9, 100);
}
