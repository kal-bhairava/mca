/*
Create a class BankAccount with:
	Private data members: accountNo, balance
	Static data member: totalAccounts
Implement: 
	A constructor to initialize the account details.
	A friend function to display the private account details.
	A static member function to display the total number of accounts created.
	Create at least three objects and demonstrate both the friend function and static member function. 
*/

#include <iostream>
#include <string>

using namespace std;

class BankAccount{
	private:
		string accountNo;
		float balance;
		string holderName;
	public:
		static int totalAccounts;
		
		BankAccount(string accountNo, string name, float balance){
			this->accountNo = accountNo;
			this->holderName = name;
			this->balance = balance; 
			totalAccounts++;
		}
		
		friend void show(BankAccount);
};

int BankAccount::totalAccounts;

void show(BankAccount a){
	cout << endl << "Account Number " << a.accountNo;
	cout << endl << "Balance " << a.balance;
	cout << endl << "Name " << a.holderName << endl;
}

int main(){
	BankAccount account1("101", "Gulam Ali", 5000), account2("102", "Mohammad Rafi", 3000), account3("103", "Mahendra Kapoor", 4000);
	
	show(account1);
	show(account2);
	show(account3);
	
	cout << "Total accounts " << BankAccount::totalAccounts;
}
