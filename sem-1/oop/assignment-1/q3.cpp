#include<iostream>

using namespace std;

int main(){
	cout << "Normal looop" << endl;
	for(int i = 0; i< 10; i++){
		cout << i << " ";
	}
	cout << endl << "Loop initilization outside" << endl;
	int i = 0;
	for(; i < 10; i++){
		cout << i << " ";
	}
	cout << endl << "Loop with increment inside loop block" << endl;
	i = 0;
	for(; i < 10;){
		cout << i++ << " ";
	}
}
