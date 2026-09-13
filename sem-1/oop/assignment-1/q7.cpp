#include<iostream>

using namespace std;

class Complex{
	float real,imaginary;
	public:
		Complex(float real, float imaginary){
			this->real = real;
			this->imaginary = imaginary;
		}
		
		float get_real(){
			return this->real;
		}
		
		float get_imaginary(){
			return this->imaginary;
		}
		
		Complex sum(Complex c){
			return Complex(c.get_real() + this->real, c.get_imaginary() + this->imaginary);
		}
		
		void display(){
			cout << "Complex number : " << this->real << " " << this->imaginary << "i" << endl;
		}
};

int main(){
	Complex complex_number = Complex(10, 20);
	complex_number.sum(Complex(20, 40)).display();
}
