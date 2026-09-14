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
	int arr[MAX_SIZE];
	int total_elms;
	cin >> total_elms;
	for(int i = 0; i < total_elms; i++){
		cin >> arr[i];
	}
	
	printArray(arr, total_elms);
	
	// reverse an array
	int p1 = 0, p2 = total_elms - 1;
	while(p1 < p2){
		swap(arr[p1], arr[p2]);
		p1++; p2--;
	}
	
	printArray(arr, total_elms);
	
	int r = 3, c = 3;
    int A[r][c] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[r][c] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int res[r][c];
	
	// matrix multiplication
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int sum = 0;
            for(int k = 0; k < c; k++){
                sum += A[i][k] * B[k][j];
            }
            res[i][j] = sum;
        }
    }
    
    for(int i = 0; i < r; i++){
        printArray(res[i], c);
    }
    
    // transpose of matrix
    int t[c][r];
    for(int i = 0; i < c; i++){
    	for(int j =0; j < r; j++){
    		t[i][j] = res[j][i];
		}
	}
	
	for(int i = 0; i < r; i++){
        printArray(t[i], c);
    }
}
