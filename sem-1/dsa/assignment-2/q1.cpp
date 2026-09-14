/*
Implement the binary search algorithm regarded as a fast search algorithm with run-time complexity of ?(log n) in comparison to the Linear Search.
*/

#include <iostream>
#define MAX 100

using namespace std;

int binarySearch(int arr[], int key, int left, int right){
	if(left > right){
		return -1;
	}
	
	int mid = left + (right - left) / 2;
	
	if(key == arr[mid]){
		return mid;
	}else if(key > arr[mid]){
		return binarySearch(arr, key, mid + 1 , right);
	}else{
		return binarySearch(arr, key, left,  mid - 1);
	}
}

int main(){
	int arr[MAX];
	int size;
	int key;
	
	cout << "Enter array size : ";
	cin >> size;
	
	cout << endl << "Enter sorted array " << endl ;
	
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	
	cout << "Enter elm to seach : ";
	cin >> key;
	
	int idx = binarySearch(arr, key, 0, size -1);
	
	cout << key << " is at index " << idx;
}
