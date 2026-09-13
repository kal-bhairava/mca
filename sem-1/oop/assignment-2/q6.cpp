#include<iostream>

using namespace std;


class Complex{
	float real, imaginary;
	public:
		Complex(){
			real = 0;
			imaginary = 1;
		}
		
		Complex(float real, float imginary){
			this->real = real;
			this->imaginary = imaginary;
		}
		
		void display(){
			cout << endl<< real << " + " << imaginary << "i";
		}
};

int main(){
	Complex c1 = Complex(), c2 = Complex(10, 20);
	c1.display();
	c2.display();
}
