#include <iostream>
#include <queue>
using namespace std;
struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
    Package(int i, string a, int s, int e) {
        id = i;
        address = a;
        startTime = s;
        endTime = e;
    }
};
class DeliverySystem {
private:
    queue<Package> q;

public:
    void enqueue(int id, string address, int start, int end) {
        q.push(Package(id, address, start, end));
        cout << "Package added: " << id << endl;
    }
    void front() {
        if (q.empty()) {
            cout << "No packages in queue\n";
            return;
        }

        Package p = q.front();
        cout << "Front Package -> ID: " << p.id
            << ", Address: " << p.address
            << ", Time: [" << p.startTime << " - " << p.endTime << "]\n";
    }
    void deliver(int currentTime) {
        if (q.empty()) {
            cout << "No packages to deliver\n";
            return;
        }

        while (!q.empty()) {
            Package p = q.front();
            if (currentTime > p.endTime) {
                cout << "Package " << p.id << " expired and skipped\n";
                q.pop();
            }
            else if (currentTime >= p.startTime && currentTime <= p.endTime) {
                cout << "Delivered Package " << p.id << endl;
                q.pop();
                return;
            }
            else {
                cout << "Package " << p.id << " is not ready " << endl;
                return;
            }
        }
        cout << "No valid packages available\n";
    }
    void display() {
        if (q.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        queue<Package> temp = q;
        cout << " Packages in Queue " << endl;
        while (!temp.empty()) {
            Package p = temp.front();
            cout << "ID: " << p.id
                << ", Address: " << p.address
                << ", Time: [" << p.startTime << " - " << p.endTime << "]\n";
            temp.pop();
        }
    }
};

int main() {
    DeliverySystem system;
    int choice, id, start, end, currentTime;
    string address;

    do {
        cout << "\n1. Add Package";
        cout << "\n2. Deliver Package";
        cout << "\n3. View Front Package";
        cout << "\n4. Display All Packages";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter ID= ";
            cin >> id;
            cout << "Enter Address  ";
            cin >> address;
            cout << "Enter Start Time= ";
            cin >> start;
            cout << "Enter End Time=  ";
            cin >> end;
            system.enqueue(id, address, start, end);
            break;
        case 2:
            cout << "Enter current time: ";
            cin >> currentTime;
            system.deliver(currentTime);
            break;
        case 3:
            system.front();
            break;
        case 4:
            system.display();
            break;
        }
    } while (choice != 0);
    return 0;
}