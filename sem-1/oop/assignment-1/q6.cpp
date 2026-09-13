#include<iostream>

using namespace std;

class Test{
	int a,b;
	public:
	Test(int param_a = 0, int param_b = 0){
		a = param_a;
		b = param_b;
	}
	
	void sum(){
		cout << "Sum is : " << a+b << endl;
		reset();
	}
	
	private:
	void reset(){
		a=0;b=0;
	}
};

int main(){
	Test t = Test(10, 3);
	t.sum();
	t.sum();
}
