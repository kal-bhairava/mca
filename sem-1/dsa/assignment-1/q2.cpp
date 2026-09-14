#include<iostream>
#include<set>

#define MAX_SIZE 100

using namespace std;

int main(){
	int arr[MAX_SIZE];
	int total_elms;
	cin >> total_elms;
	for(int i = 0; i < total_elms; i++){
		cin >> arr[i];
	}
	
	set<int> s;
	for(int i = 0; i < total_elms; i++){
		s.insert(arr[i]);
	}
	
	cout << "Duplicates removed : " << endl;
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
		cout << *it << " ";  
	}
}
