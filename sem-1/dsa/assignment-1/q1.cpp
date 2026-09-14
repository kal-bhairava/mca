#include<iostream>
#define MAX_SIZE 100
using namespace std;

int main(){
	char y_n;
	int arr[MAX_SIZE];
	int top = -1;
	int array_size = 0;
	do{
		int opt;
		cout << endl << "1 :  Create Array" << endl;
		cout << "2 :  Display" << endl;
		cout << "3 :  Insert" << endl;
		cout << "4 :  Delete" << endl;
		cout << "5 :  Linear Search" << endl;
		cout << "6 :  Exit" << endl;
		
		cout << "Choose : ";
		cin >> opt;
		
		switch(opt){
			case 1:
				cout << endl << "Enter new arary size : ";
				cin >> array_size;
				break;
			case 2:
				for(int i = 0; i < array_size; i++){
					cout << arr[i] << " ";
				}
				break;
			case 3:
				int elm;
				cout << endl << "Enter elm to insert : ";
				cin >> elm;
				arr[++top] = elm;
				break;
			case 4:
				int elm_to_remove;
				cout << endl << "Enter elm to remove : ";
				cin >> elm_to_remove;
				int i;
				for(i = 0; i < array_size; i++){
					if(arr[i] == elm_to_remove){
						break;
					}
				}
				
				for(int j = i; j < array_size; j++){
					arr[j] = arr[j+1];
				}
				
				break;
			case 5:{
				int elm;
				cout << endl << "Enter elm to search : ";
				cin >> elm;
				int i;
				bool found = 0;
				for(i = 0; i < array_size; i++){
					if(arr[i] == elm_to_remove){
						found = 1;
						break;
					}
				}
				found ? cout << endl << "Elm found at index : " << i : "Not found";
				break;
			}
			case 6:
				exit(0);
				break;
			default:
				cout << "Choose a valid option " << endl;
		}
		cout << "Press Y/N to coniute or exit: ";
		cin >> y_n;
	}while(y_n == 'Y' || y_n == 'y');
}
