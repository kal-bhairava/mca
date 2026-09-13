#include<iostream>
using namespace std;

class Rectangle{
	float length, breadth;
	public : 
		Rectangle(float l, float b){
			length = l;
			breadth = b;
		}
		
		void area(){
			cout << "Area is : " << (length * breadth);
		}
};

int main(){
	Rectangle r = Rectangle(10, 20);
	r.area();
}
