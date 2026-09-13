#include<iostream>
#include<string>

using namespace std;

class Demo{
	public:
		Demo(){
			cout << endl << this << " initialized";
		}
		
		~Demo(){
			cout << endl << this << " destroid";
		}
};

int main(){
	Demo d1, d2, d3;
}
