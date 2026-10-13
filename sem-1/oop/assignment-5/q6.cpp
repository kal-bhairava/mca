/*
Create a class Bill with overloaded functions named calculateBill() to calculate:
	The bill for one item using quantity and unit price.
	The bill for two items using their quantities and prices.
	The bill for a bill amount after applying a discount percentage.
	Use suitable parameter lists and return the final bill amount. 
*/

#include <iostream>
using namespace std;

class Bill {
public:
    double calculateBill(int qty, double price) {
        return qty * price;
    }

    double calculateBill(int qty1, double price1,
                         int qty2, double price2) {
        return (qty1 * price1) + (qty2 * price2);
    }

    double calculateBill(double amount, double discount) {
        return amount - (amount * discount / 100);
    }
};

int main() {
    Bill b;

    double bill1 = b.calculateBill(4, 100.5);
    cout << "Bill for one item: " << bill1 << endl;

    double bill2 = b.calculateBill(2, 100.0, 3, 50.0);
    cout << "Bill for two items: " << bill2 << endl;

    double finalBill = b.calculateBill(bill1, 10.0);
    cout << "Final bill after 10% discount: "
         << finalBill << endl;

    return 0;
}
