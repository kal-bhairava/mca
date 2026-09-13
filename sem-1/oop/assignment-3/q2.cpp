/*
Create a class Number with two private data members a and b.
Use a friend function to access these members and calculate and display their sum. 
*/

#include <iostream>

using namespace std;

class Number{
	private:
		int a, b;
	public:
		Number(int a, int b){
			this->a = a;
			this->b = b;
		}
		friend void sum(Number);
};

void sum(Number n){
	cout << n.a + n.b;
}

int main(){
	Number n(10, 20);
	sum(n);
}
