/*
Create a C++ program to demonstrate Hierarchical Inheritance.
Create a base class Vehicle containing:
Brand
Model
Create two derived classes:
Car -> Number of Doors
Bike -> Engine Capacity
Create separate objects of Car and Bike and display their respective details.
*/

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    string model;

public:
    void acceptVehicle() {
        cout << "Enter Brand: ";
        getline(cin, brand);
        cout << "Enter Model: ";
        getline(cin, model);
    }

    void displayVehicle() const {
        cout << "Brand  : " << brand << endl;
        cout << "Model  : " << model << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    void acceptCar() {
        cout << "--- Enter Car Details ---\n";
        acceptVehicle();
        cout << "Enter Number of Doors: ";
        cin >> numDoors;
    }

    void displayCar() const {
        cout << "\n--- Car Details ---\n";
        displayVehicle();
        cout << "Doors  : " << numDoors << endl;
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity; 

public:
    void acceptBike() {
        cout << "--- Enter Bike Details ---\n";
        acceptVehicle();
        cout << "Enter Engine Capacity (CC): ";
        cin >> engineCapacity;
        cin.ignore(); 
    }

    void displayBike() const {
        cout << "\n--- Bike Details ---\n";
        displayVehicle();
        cout << "Engine : " << engineCapacity << " CC" << endl;
    }
};

int main() {
    Car myCar;
    Bike myBike;

    myCar.acceptCar();
    myCar.displayCar();

    cout << endl;

    myBike.acceptBike();
    myBike.displayBike();

    return 0;
}
