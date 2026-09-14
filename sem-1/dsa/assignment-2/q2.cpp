/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
Code the Bubble sort with the following elements: 
64 34 25 12 22 11 90
*/

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int length){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main(){
	int length = 7;
	int arr[7] = { 64, 34, 25, 12, 22, 11, 90 };
	
	bubbleSort(arr, length);
	
	for(int i = 0; i < length; i++){
		cout << arr[i] << ", ";
	}
}
