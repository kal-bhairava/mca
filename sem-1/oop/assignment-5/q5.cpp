/*
Create a class Maximum with overloaded functions named findMax():
	findMax(int a, int b) — find the greater of two integers.
	findMax(int a, int b, int c) — find the greatest of three integers.
	findMax(double a, double b) — find the greater of two decimal numbers. 
*/

#include <iostream>
using namespace std;

class Maximum{
	public:
		int findMax(int a, int b){
			return a > b ? a : b;
		}
		
		int findMax(int a, int b, int c){
			return a > b && a > c ? a : b > c ? b : c;
		}
		
		double findMax(double a, double b){
			return a > b ? a : b;
		}
};

int main(){
	Maximum m;
	cout << endl << m.findMax(10.2, 10.1);
	cout << endl << m.findMax(10, 11);
	cout << endl << m.findMax(3, 2, 1);
	cout << endl << m.findMax(1, 3, 2);
	cout << endl << m.findMax(1, 2, 3);
	return 0;
}
