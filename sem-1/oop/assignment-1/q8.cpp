#include<iostream>
#include<string>

using namespace std;

namespace college_one{
	string name = "College One";
	
	void display(){
		cout << name << endl;
	}
};

namespace college_two{
	string name = "College Two";
	
	void display(){
		cout << name << endl;
	}
};

int main(){
	cout << college_one::name << endl;
	cout << college_two::name << endl;
	college_two::display();
	college_one::display();
}
