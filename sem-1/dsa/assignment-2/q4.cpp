/*
String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

void concat(char a[], char b[], char res[]) {
    int i = 0;
    int j = 0;
    
    while (a[i] != '\0') {
        res[i] = a[i];
        i++;
    }
    
    while (b[j] != '\0') {
        res[i] = b[j];
        i++;
        j++;
    }
    
    res[i] = '\0';
}

void removeVowels(char c[]){
	int write_idx = 0;
    int read_idx = 0;
	while(c[read_idx] != '\0'){
        char ch = c[read_idx];
        
        if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
             ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')){
            c[write_idx] = c[read_idx];
            write_idx++;
        }
        read_idx++;
    }
    
    c[write_idx] = '\0';
}

void reverse(char a[], int size){
	int left = 0;
	int right = size -1;
	
	while(left < right){
		swap(a[left], a[right]);
		left++;
		right--;
	}
}

void sort(char str[], int len){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len - i -1; j++){
			if(str[j] > str[j + 1]){
				swap(str[j], str[j+1]);
			}
		}
	}
}

void upper(char str[], int length){
	int lower_min = int('a'); // 97
    int lower_max = int('z'); // 122
    int upper_min = int('A'); // 65
	
	for(int i = 0; i < length; i++){
        if(str[i] >= lower_min && str[i] <= lower_max){
            str[i] = str[i] - (lower_min - upper_min);
        }	
    }
}

void lower(char str[], int length){
	int lower_min = int('a'); // 97
    int lower_max = int('z'); // 122
    int upper_min = int('A'); // 65
    int upper_max = int('Z'); // 90
	
	for(int i = 0; i < length; i++){
        if(str[i] >= upper_min && str[i] <= upper_max){
            str[i] = str[i] + (lower_min - upper_min);
        }	
    }
}

int main(){
	char* a = "abc";
	char* b = "def";
	char c[100];
	concat(a, b, c);
	cout << c;
	reverse(c, 6);
	cout << endl << "Reversed " << c;
	removeVowels(c);
	cout << endl << c;
	char s[] = "ertabc";
	sort(s, 6);
	cout << endl << s;
	upper(s, 6);
	cout << endl << s;
	lower(s, 6);
	cout << endl << s;
}
