#include <iostream>
#include <queue>
#include <string>
using namespace std;
class PrintQueue {
private:
    queue<string> q;

public:
    void enqueue(string doc) {
        q.push(doc);
        cout << "Document added: " << doc << endl;
    }
    void dequeue() {
        if (q.empty()) {
            cout << "No documents to print\n";
            return;
        }
        cout << "Printing: " << q.front() << endl;
        q.pop();
    }
    void front() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Next document: " << q.front() << endl;
    }
    void display() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        queue<string> temp = q; 
        cout << "Pending Documents:\n";
        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {
    PrintQueue printer;
    int choice;
    string doc;

    do {
        cout << "\n1. Add Print Job";
        cout << "\n2. Print Document";
        cout << "\n3. View Next Document";
        cout << "\n4. Display All Jobs";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> doc;
            printer.enqueue(doc);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            printer.display();
            break;
        }

    } while (choice != 0);

    return 0;
}