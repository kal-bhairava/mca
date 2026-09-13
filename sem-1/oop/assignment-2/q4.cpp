#include<iostream>
#include<string>

using namespace std;

class Box{
	float length, width, height;
	
	public:
		Box(){
			length = 0;
			width = 0;
			height = 0;
		}
		
		Box(float length, float width, float height){
			this->length = length;
			this->width = width;
			this->height = height;
		}
		
		void volume(){
			cout << "Volume : " << this->length * this->width * this->height;
		}
};

int main(){
	Box b = Box(10,20,30);
	b.volume();
}
