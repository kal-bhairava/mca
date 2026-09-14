#include<iostream>
#define MAX_SIZE 100

using namespace std;

int main(){
	int arr[MAX_SIZE];
	int total_elms;
	cin >> total_elms;
	for(int i = 0; i < total_elms; i++){
		cin >> arr[i];
	}
	
	int rotations;
	cout << "Enter no of rotations : ";
	cin >> rotations;
	
	for(int r = 0; r < rotations; r++){
		int tmp = arr[0];
		for(int i = 0; i < total_elms - 1; i++){
			arr[i] = arr[i+1];
		}
		arr[total_elms - 1] = tmp;
	}
	
	cout << endl << "Final Array " << endl;
	for(int i = 0; i < total_elms; i++){
		cout << arr[i] << " ";
	}
}
