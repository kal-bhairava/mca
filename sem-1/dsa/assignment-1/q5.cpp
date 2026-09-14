#include<iostream>
#define MAX_SIZE 100

using namespace std;

void printArray(int arr[], int size){
	cout << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int r = 3, c = 3;
    int A[r][c] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[r][c] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // sum of every row
    for(int i = 0; i < r; i++){
    	for(int j = 1; j < c; j++){
    		A[i][j] += A[i][j-1];
		}
	}
	
	for(int i = 0; i < r; i++){
        printArray(A[i], c);
    }
    
    // sum of every columns
    for(int i = 1; i < r; i++){
    	for(int j = 0; j < c; j++){
    		B[i][j] += B[i - 1][j];
		}
	}
	
	for(int i = 0; i < r; i++){
        printArray(B[i], c);
    }
}
