#include<iostream>
#include"QueueUsingStacks.h"
using namespace std;
int main() {
    QueueUsingStacks<int> q;
    int choice, value;
    do {
        cout << "\n--- Queue using Stacks ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "Removed " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Front " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice  ";
        }

    } while (choice != 5);
    return 0;
}