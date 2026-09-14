/*
Design the Logic to Find a Missing Number in a Sorted Array. =
Given an array of n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array 
(a) Linear time 
(b) Using binary search. 
*/


#include <iostream>

using namespace std;

int linearTimeMissingNumber(int arr[], int n){
	for(int i = 0; i < n; i++){
		if(arr[i] != i + 1){
			return i + 1;
		}
	}
	
	return -1;
}

int logTimeMissingNumber(int arr[], int left, int right){
	
	if(left > right){
		return left + 1;
	}
	
	int mid = left + (right - left) / 2;
	
	if(arr[mid] == mid + 1){
		return logTimeMissingNumber(arr, mid + 1, right);
	}else{
		return logTimeMissingNumber(arr, left, mid - 1);
	}
}


int main(){
	int arr[] = {1, 2, 3, 4, 6};
//	int missing = linearTimeMissingNumber(arr, 6);
	int missing = logTimeMissingNumber(arr, 0, 6);
	
	cout << "In array missing number is " << missing;
}
