#include<iostream>
#include<string>

using namespace std;

class Demo{
	string msg;
	public:
		Demo(string msg){
			this->msg = msg;
			cout << endl << this->msg << " initialized";
		}
		
		~Demo(){
			cout << endl << this->msg << " destroid";
		}
};

void othr(){
	Demo d = Demo("outside");
}

int main(){
	Demo d1 = Demo("d1"), d2 = Demo("d2"), d3 = Demo("d3");
	othr();
}
