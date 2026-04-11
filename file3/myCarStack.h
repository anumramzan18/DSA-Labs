#include <iostream>
#include "myCarStack.h"
using namespace std;
int main() {
    myCarStack parking;
    int choice;
    string car;
    do {
        cout << endl;
        cout << "===== PARKING SYSTEM =====" << endl;
        cout << "1. Park a car" << endl;
        cout << "2. Remove a car" << endl;
        cout << "3. View parked cars" << endl;
        cout << "4. Total cars parked" << endl;
        cout << "5. Search car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
            break;
            case 2:
            cout << "Enter car number to remove: ";
            cin >> car;
            parking.removeCar(car);
            break;
            case 3:
            parking.display();
            break;
            case 4:
            cout << "Total cars parked: " << parking.count() << endl;
            break;
            case 5:
            cout << "Enter car number to search: ";
            cin >> car;
            if (parking.search(car))
                cout << "Car is present in parking." << endl;
            else
                cout << "Car not found." << endl;
            break;
            case 6:
            cout << "Exiting..." << endl;
            break;
            default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);
    return 0;
}