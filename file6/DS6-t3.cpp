#include <iostream>
#include <string>
using namespace std;
class QNode {
public:
    string flightID;
    QNode* next;
    QNode(string id) {
        flightID = id;
        next = NULL;
    }
};

class FlightQueue {
private:
    QNode *front, *rear;

public:
    FlightQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }
    void enqueue(string id) {
        QNode* temp = new QNode(id);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    string dequeue() {
        if (isEmpty()) return "";
        QNode* temp = front;
        string id = temp->flightID;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
        return id;
    }
    void displayQueue(string type) {
        cout << type << " Queue: ";
        QNode* temp = front;
        if (!temp) cout << "[Empty]";
        while (temp != NULL) {
            cout << temp->flightID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
      FlightQueue EmergencyQueue, PassengerQueue, CargoQueue;
    PassengerQueue.enqueue("P1");
    CargoQueue.enqueue("C1");
    EmergencyQueue.enqueue("E1");
    PassengerQueue.enqueue("P2");
    CargoQueue.enqueue("C2");
    EmergencyQueue.enqueue("E2");
    cout << "AIRPORT RUNWAY SCHEDULING SYSTEM" << endl;
    cout << "\n--- Current Flight Queues ---" << endl;
    EmergencyQueue.displayQueue("Emergency (High)");
    PassengerQueue.displayQueue("Passenger (Medium)");
    CargoQueue.displayQueue("Cargo     (Low)");
    cout << "\n--- Final Landing Order ---" << endl;
    int step = 1;
    while (!EmergencyQueue.isEmpty() || !PassengerQueue.isEmpty() || !CargoQueue.isEmpty()) {
        cout << step++ << ". ";
        if (!EmergencyQueue.isEmpty()) {
            cout << "LANDED: " << EmergencyQueue.dequeue() << " [Category: EMERGENCY]" << endl;
        } 
        else if (!PassengerQueue.isEmpty()) {
            cout << "LANDED: " << PassengerQueue.dequeue() << " [Category: PASSENGER]" << endl;
        } 
        else {
            cout << "LANDED: " << CargoQueue.dequeue() << " [Category: CARGO]" << endl;
        }
    }
    cout << "\nAll flights have landed safely. Runway is clear." << endl;
    return 0;
}