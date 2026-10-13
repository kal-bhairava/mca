/*
Create a class Print with overloaded display() functions to display an integer, a double value, and a string. 
*/

#include <iostream>
#include <string>
using namespace std;


class Print{
	public :
		void display(int a){
			cout << "Int : " << a << endl;
		}
		void display(double a){
			cout << "Double : " << a << endl;
		}
		void display(string a){
			cout << "String : " << a << endl;
		}
};

int main(){
	Print p;
	p.display(10);
	p.display(10.2);
	p.display("Programming OOP");
	return 0;
}
